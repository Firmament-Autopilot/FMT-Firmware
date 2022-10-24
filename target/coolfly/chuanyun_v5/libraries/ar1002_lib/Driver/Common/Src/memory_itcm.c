#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "lock.h"
#include "debuglog.h"
#include "memory_itcm.h"

/* sbrk implementation start */

extern char end_itcm;
extern char _physical_end_itcm;
static unsigned int mem_malloc_start_itcm = (((unsigned int)(&end_itcm)) + 0);
static unsigned int mem_malloc_end_itcm = ((unsigned int)(&_physical_end_itcm));
static unsigned int mem_malloc_brk_itcm = (((unsigned int)(&end_itcm)) + 0);
#define MORECORE_FAILURE (-1)

#define MAX(a,b) ((a) >= (b) ? (a) : (b))

static void *sbrk_itcm(ptrdiff_t increment)
{
    unsigned int old = mem_malloc_brk_itcm;
    unsigned int new = old + increment;

    //get_mem_malloc_end_itcm();

    /*
     * if we are giving memory back make sure we clear it out since
     * we set MORECORE_CLEARS to 1
     */
    if (increment < 0)
    {
        memset((void *)new, 0, -increment);
    }

    /*DLOG_Critical("mem_malloc_start_itcm:0x%x mem_malloc_end_itcm:0x%x",
                    mem_malloc_start_itcm, mem_malloc_end_itcm);*/
    if ((new < mem_malloc_start_itcm) || ((new + 0) > mem_malloc_end_itcm))
    {
        DLOG_Error("malloc out of boundary!");
        return (void *)MORECORE_FAILURE;
    }

    mem_malloc_brk_itcm = new;

    DLOG_Info("brk = 0x%x, sp = 0x%x", mem_malloc_brk_itcm, mem_malloc_end_itcm);

    return (void *)old;
}

/* sbrk implementation end */

/* newlib nano_malloc and nano_free start */

#define RARG
#define RONEARG
#define RCALL
#define RONECALL
#if 0

#else
#define MALLOC_LOCK       do { s_ul_primask = rt_hw_interrupt_disable(); } while(0);
#endif
#define MALLOC_UNLOCK     do { rt_hw_interrupt_enable(s_ul_primask); } while(0);
#define RERRNO errno

static lock_type s_heap_lock = UNLOCK_STATE;
static long s_ul_primask  = 0;
static unsigned int errno = 0 ;

#define ALIGN_TO(size, align) \
    (((size) + (align) -1L) & ~((align) -1L))

/* Alignment of allocated block */
#define MALLOC_ALIGN (8U)
#define CHUNK_ALIGN (sizeof(void*))
#define MALLOC_PADDING ((MAX(MALLOC_ALIGN, CHUNK_ALIGN)) - CHUNK_ALIGN)

/* as well as the minimal allocation size
 * to hold a free pointer */
#define MALLOC_MINSIZE (sizeof(void *))
#define MAX_ALLOC_SIZE_ITCM ((unsigned int)(mem_malloc_end_itcm - mem_malloc_start_itcm))

#define ENOMEM    12

#define _SBRK_R_ITCM(X) sbrk_itcm(X)


typedef size_t malloc_size_t;

typedef struct malloc_chunk
{
    /*          ------------------
     *   chunk->| size (4 bytes) |
     *          ------------------
     *          | Padding for    |
     *          | alignment      |
     *          | holding neg    |
     *          | offset to size |
     *          ------------------
     * mem_ptr->| point to next  |
     *          | free when freed|
     *          | or data load   |
     *          | when allocated |
     *          ------------------
     */
    /* size of the allocated payload area, including size before
       CHUNK_OFFSET */
    long size;

    /* since here, the memory is either the next free block, or data load */
    struct malloc_chunk * next;
}chunk;

#define CHUNK_OFFSET ((malloc_size_t)(&(((struct malloc_chunk *)0)->next)))

/* size of smallest possible chunk. A memory piece smaller than this size
 * won't be able to create a chunk */
#define MALLOC_MINCHUNK (CHUNK_OFFSET + MALLOC_PADDING + MALLOC_MINSIZE)

static inline chunk * get_chunk_from_ptr(void * ptr)
{
    chunk * c = (chunk *)((char *)ptr - CHUNK_OFFSET);
    /* Skip the padding area */
    if (c->size < 0) c = (chunk *)((char *)c + c->size);
    return c;
}

/* List list header of free blocks */
chunk * free_list_itcm = NULL;

/* Starting point of memory allocated from system */
char * sbrk_start_itcm = NULL;

/** Function sbrk_aligned
  * Algorithm:
  *   Use sbrk() to obtain more memory and ensure it is CHUNK_ALIGN aligned
  *   Optimise for the case that it is already aligned - only ask for extra
  *   padding after we know we need it
  */
static void* sbrk_aligned_itcm(RARG malloc_size_t s)
{
    char *p, *align_p;

    if (sbrk_start_itcm == NULL) sbrk_start_itcm = _SBRK_R_ITCM(RCALL 0);

    p = _SBRK_R_ITCM(RCALL s);

    /* sbrk returns -1 if fail to allocate */
    if (p == (void *)-1)
        return p;

    align_p = (char*)ALIGN_TO((unsigned long)p, CHUNK_ALIGN);
    if (align_p != p)
    {
        /* p is not aligned, ask for a few more bytes so that we have s
         * bytes reserved from align_p. */
        p = _SBRK_R_ITCM(RCALL align_p - p);
        if (p == (void *)-1)
            return p;
    }
    return align_p;
}


/** Function nano_malloc
  * Algorithm:
  *   Walk through the free list to find the first match. If fails to find
  *   one, call sbrk to allocate a new chunk.
  */
void * nano_malloc_itcm(RARG malloc_size_t s)
{
    chunk *p, *r;
    char * ptr, * align_ptr;
    int offset;
    // int step = 0;

    malloc_size_t alloc_size;

    alloc_size = ALIGN_TO(s, CHUNK_ALIGN); /* size of aligned data load */
    alloc_size += MALLOC_PADDING; /* padding */
    alloc_size += CHUNK_OFFSET; /* size of chunk head */
    alloc_size = MAX(alloc_size, MALLOC_MINCHUNK);

    if (alloc_size >= MAX_ALLOC_SIZE_ITCM || alloc_size < s)
    {
        RERRNO = ENOMEM;
        return NULL;
    }

    p = free_list_itcm;
    r = p;

    while (r)
    {
        int rem = r->size - alloc_size;
        if (rem >= 0)
        {
            if (rem >= MALLOC_MINCHUNK)
            {
                /* Find a chunk that much larger than required size, break
                * it into two chunks and return the second one */
                r->size = rem;
                r = (chunk *)((char *)r + rem);
                r->size = alloc_size;
            }
            /* Find a chunk that is exactly the size or slightly bigger
             * than requested size, just return this chunk */
            else if (p == r)
            {
                /* Now it implies p==r==free_list. Move the free_list
                 * to next chunk */
                free_list_itcm = r->next;
            }
            else
            {
                /* Normal case. Remove it from free_list */
                p->next = r->next;
            }
            break;
        }
        p=r;
        r=r->next;
    }

    /* Failed to find a appropriate chunk. Ask for more memory */
    if (r == NULL)
    {
        r = sbrk_aligned_itcm(RCALL alloc_size);

        /* sbrk returns -1 if fail to allocate */
        if (r == (void *)-1)
        {
            RERRNO = ENOMEM;
            MALLOC_UNLOCK;
            return NULL;
        }
        r->size = alloc_size;
    }
    MALLOC_UNLOCK;

    ptr = (char *)r + CHUNK_OFFSET;

    align_ptr = (char *)ALIGN_TO((unsigned long)ptr, MALLOC_ALIGN);
    offset = align_ptr - ptr;

    if (offset)
    {
        *(int *)((char *)r + offset) = -offset;
    }

    //assert(align_ptr + size <= (char *)r + alloc_size);
    return align_ptr;
}


#define MALLOC_CHECK_DOUBLE_FREE

/** Function nano_free
  * Implementation of libc free.
  * Algorithm:
  *  Maintain a global free chunk single link list, headed by global
  *  variable free_list.
  *  When free, insert the to-be-freed chunk into free list. The place to
  *  insert should make sure all chunks are sorted by address from low to
  *  high.  Then merge with neighbor chunks if adjacent.
  */
void nano_free_itcm (RARG void * free_p)
{
    chunk * p_to_free;
    chunk * p, * q;

    if (free_p == NULL) return;

    p_to_free = get_chunk_from_ptr(free_p);

    if (free_list_itcm == NULL)
    {
        /* Set first free list element */
        p_to_free->next = free_list_itcm;
        free_list_itcm = p_to_free;
        return;
    }

    if (p_to_free < free_list_itcm)
    {
        if ((char *)p_to_free + p_to_free->size == (char *)free_list_itcm)
        {
            /* Chunk to free is just before the first element of
             * free list  */
            p_to_free->size += free_list_itcm->size;
            p_to_free->next = free_list_itcm->next;
        }
        else
        {
            /* Insert before current free_list */
            p_to_free->next = free_list_itcm;
        }
        free_list_itcm = p_to_free;
        return;
    }

    q = free_list_itcm;
    /* Walk through the free list to find the place for insert. */
    do
    {
        p = q;
        q = q->next;
    } while (q && q <= p_to_free);

    /* Now p <= p_to_free and either q == NULL or q > p_to_free
     * Try to merge with chunks immediately before/after it. */

    if ((char *)p + p->size == (char *)p_to_free)
    {
        /* Chunk to be freed is adjacent
         * to a free chunk before it */
        p->size += p_to_free->size;
        /* If the merged chunk is also adjacent
         * to the chunk after it, merge again */
        if ((char *)p + p->size == (char *) q)
        {
            p->size += q->size;
            p->next = q->next;
        }
    }
#ifdef MALLOC_CHECK_DOUBLE_FREE
    else if ((char *)p + p->size > (char *)p_to_free)
    {
        /* Report double free fault */
        RERRNO = ENOMEM;
        return;
    }
#endif
    else if ((char *)p_to_free + p_to_free->size == (char *) q)
    {
        /* Chunk to be freed is adjacent
         * to a free chunk after it */
        p_to_free->size += q->size;
        p_to_free->next = q->next;
        p->next = p_to_free;
    }
    else
    {
        /* Not adjacent to any chunk. Just insert it. Resulting
         * a fragment. */
        p_to_free->next = q;
        p->next = p_to_free;
    }
}

/* newlib nano_malloc and nano_free end */
static void *malloc_itcm(size_t size)
{
    return nano_malloc_itcm(size);
}

static void free_itcm(void *ap)
{
    nano_free_itcm(ap);
}

void *realloc_itcm_safe(void *ptr, size_t size)
{
    void *new;

    new = malloc_itcm_safe(size);
    if (!new)
    {
        return NULL;
    }
	memcpy(new, ptr, size);
    if (ptr)    
    {
        free_itcm_safe(ptr);
    }

    return new;
}

void *calloc_itcm_safe (size_t n, size_t elem_size)
{
    void *result;
    size_t sz = n * elem_size;

    result = malloc_itcm_safe(sz);
    if (result != NULL)
        memset (result, 0, sz);

    return result;
}

void *malloc_itcm_safe(size_t size)
{
    void *p = NULL;

    unsigned long primask = rt_hw_interrupt_disable();
    p = malloc_itcm(size);
    rt_hw_interrupt_enable(primask);

    return p;
}

void free_itcm_safe(void *ap)
{
    unsigned long primask = rt_hw_interrupt_disable();
    free_itcm(ap);
    rt_hw_interrupt_enable(primask);
}
