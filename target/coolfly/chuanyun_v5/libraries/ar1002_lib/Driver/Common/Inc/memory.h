#ifndef MEMORY_H
#define MEMORY_H

#ifdef __cplusplus
extern "C" {
#endif

void *malloc_safe(size_t size);

void free_safe(void *ap);

void *realloc_safe(void *ptr, size_t size);

void *calloc_safe(size_t n, size_t elem_size);

void memory_malloc_free_check(void);

#ifdef __cplusplus
}
#endif

#endif
