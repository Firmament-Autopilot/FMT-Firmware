/*
 * Stub version of chown.
 */


#include <_ansi.h>
#include <stdlib.h>
#include <_syslist.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/times.h>
#include <limits.h>
#include <string.h>
#include "debuglog.h"
#include "nosys.h"

#undef errno
extern int errno;

static unsigned long malloc_cnt, free_cnt;
int _chown(const char *path,
           uid_t owner,
           gid_t group)
{
  errno = ENOSYS;
  return -1;
}

/*
 * Stub version of close.
 */

int _close(int fildes)
{
  errno = ENOSYS;
  return -1;
}


/*
 * Version of environ for no OS.
 */
char *__env[1] = { 0 }; 
char **environ = __env; 
/* Supply a definition of errno if one not already provided.  */

/*
 * Stub version of execve.
 */
int _execve(char  *name,
           char **argv,
           char **env)
{
  errno = ENOSYS;
  return -1;
}


/*
 * Stub version of fork.
 */
int _fork(void)
{
  errno = ENOSYS;
  return -1;
}



/*
 * Stub version of fstat.
 */
int _fstat(int fildes,
           struct stat *st)
{
  errno = ENOSYS;
  return -1;
}


/*
 * Stub version of getpid.
 */
int _getpid(void)
{
  errno = ENOSYS;
  return -1;
}


/*
 * Stub version of gettimeofday.
 */
// int _gettimeofday(struct timeval  *ptimeval,
//                   void *ptimezone)
// {
//   errno = ENOSYS;
//   return -1;
// }


/*
 * Stub version of isatty.
 */


int _isatty(int file)
{
  errno = ENOSYS;
  return 0;
}


/*
 * Stub version of kill.
 */

int _kill(int pid,
          int sig)
{
  errno = ENOSYS;
  return -1;
}


/*
 * Stub version of link.
 */

int _link(char *existing,
          char *new)
{
  errno = ENOSYS;
  return -1;
}


/*
 * Stub version of lseek.
 */

int _lseek(int   file,
           int   ptr,
           int   dir)
{
  errno = ENOSYS;
  return -1;
}


/*
 * Stub version of open.
 */
int _open(char *file,
          int   flags,
          int   mode)
{
  errno = ENOSYS;
  return -1;
}



/*
 * Stub version of read.
 */
int _read(int   file,
          char *ptr,
          int   len)
{
  errno = ENOSYS;
  return -1;
}



/*
 * Stub version of readlink.
 */
int _readlink(const char *path,
              char *buf,
              size_t bufsize)
{
  errno = ENOSYS;
  return -1;
}



/*
 * Stub version of stat.
 */
int _stat(const char  *file,
         struct stat *st)
{
  errno = ENOSYS;
  return -1;
}


/*
 * Stub version of symlink.
 */

int _symlink(const char *path1,
             const char *path2)
{
  errno = ENOSYS;
  return -1;
}



/*
 * Stub version of times.
 */
clock_t _times(struct tms *buf)
{
  errno = ENOSYS;
  return -1;
}



/*
 * Stub version of unlink.
 */
int _unlink(char *name)
{
  errno = ENOSYS;
  return -1;
}


/*
 * Stub version of wait.
 */
int _wait(int  *status)
{
  errno = ENOSYS;
  return -1;
}



/* Stub version of _exit.  */
void _exit(int rc)
{
  /* Default stub just causes a divide by 0 exception.  */
  int x = rc / INT_MAX;
  x = 4 / x;

  /* Convince GCC that this function never returns.  */
  for (;;)
    ;
}

extern unsigned int DLOG_StrCpyToDebugOutputLogBuf(const char *src, unsigned int length);

// Output data when use libc.a
int _write(int file, char *ptr, int len)
{
    int len2;
    
    if ((file == 0) || (file == 1) || (file ==2))
    {
        if ((len > 2) && ('\n' == ptr[len-1]) && (DEBUG_LOG_END == ptr[len-2]))
        {
            len2 = len -1;
        }
        else
        {
            len2 = len;
        }
        // Print to buffer
        DLOG_StrCpyToDebugOutputLogBuf(ptr, len2);
    }

    return len;
}


/* _sbrk implementation start */

extern char end;
static unsigned int mem_malloc_start = (unsigned int)(&end);
static unsigned int mem_malloc_end;
static unsigned int mem_malloc_brk = (unsigned int)(&end);
#define MORECORE_FAILURE (-1)

#define MAX(a,b) ((a) >= (b) ? (a) : (b))

static inline void stack_get_position(void) __attribute__((optimize("O0")));

static inline void stack_get_position(void)
{
    __asm("MRS R0, MSP");
    __asm("LDR R1, =mem_malloc_end");    
    __asm("STR R0, [R1]");
}

void *_sbrk(ptrdiff_t increment)
{
    unsigned int old = mem_malloc_brk;
    unsigned int new = old + increment;

    stack_get_position();

    /*
     * if we are giving memory back make sure we clear it out since
     * we set MORECORE_CLEARS to 1
     */
    if (increment < 0)
    {
        memset((void *)new, 0, -increment);
    }

    if ((new < mem_malloc_start) || ((new + 2048) > mem_malloc_end))
    {
        return (void *)MORECORE_FAILURE;
    }

    mem_malloc_brk = new;

    return (void *)old;
}


/* _sbrk implementation end */

void *malloc_safe(size_t size)
{
    void *p = NULL;

    unsigned long primask = rt_hw_interrupt_disable();
    p = malloc(size);
    rt_hw_interrupt_enable(primask);

    malloc_cnt += (p != NULL);

    return p;
}

void free_safe(void *ap)
{
    if (ap)
    {
        unsigned long primask = rt_hw_interrupt_disable();
        free(ap);
        rt_hw_interrupt_enable(primask);

        free_cnt ++;
    }
}


void *realloc_safe(void *ptr, size_t size)
{
    void *new;

    new = malloc_safe(size);
    if (!new)
    {
        free_safe (ptr);
        return NULL;
    }
    memcpy(new, ptr, size);
    if (ptr)
    {
        free_safe(ptr);
    }

    return new;
}

void *calloc_safe(size_t n, size_t elem_size)
{
    void *result;
    size_t sz = n * elem_size;

    result = malloc_safe (sz);
    if (result != NULL)
        memset (result, 0, sz);

    return result;
}

void memory_malloc_free_check(void)
{
    DLOG_Warning("%ld %ld", malloc_cnt, free_cnt);
}


// These magic symbols are provided by the linker.
extern void
(*__preinit_array_start[])(void) __attribute__((weak));

extern void
(*__preinit_array_end[])(void) __attribute__((weak));

extern void
(*__init_array_start[])(void) __attribute__((weak));

extern void
(*__init_array_end[])(void) __attribute__((weak));

extern void
(*__fini_array_start[])(void) __attribute__((weak));

extern void
(*__fini_array_end[])(void) __attribute__((weak));


// Iterate over all the preinit/init routines (mainly static constructors).
void cpp_run_init_array(void) 
{
  int count;
  int i;

  count = __preinit_array_end - __preinit_array_start;
   for (i = 0; i < count; i++)
   {
       __preinit_array_start[i]();
   }

  // If you need to run the code in the .init section, please use
  // the startup files, since this requires the code in crti.o and crtn.o
  // to add the function prologue/epilogue.
  //_init(); // DO NOT ENABE THIS!

  count = __init_array_end - __init_array_start;
  for (i = 0; i < count; i++)
    __init_array_start[i]();
}



// Run all the cleanup routines (mainly static destructors).
void cpp_run_fini_array(void) 
{
  int count;
  int i;

  count = __fini_array_end - __fini_array_start;
  for (i = count; i > 0; i--)
  {
      __fini_array_start[i - 1]();
  }

  // If you need to run the code in the .fini section, please use
  // the startup files, since this requires the code in crti.o and crtn.o
  // to add the function prologue/epilogue.
  //_fini(); // DO NOT ENABE THIS!
}

