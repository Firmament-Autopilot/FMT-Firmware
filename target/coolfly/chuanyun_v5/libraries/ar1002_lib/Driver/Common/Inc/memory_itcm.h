#ifndef MEMORY_ITCM_H
#define MEMORY_ITCM_H

#ifdef __cplusplus
extern "C" {
#endif

void *malloc_itcm_safe(size_t size);

void free_itcm_safe(void *ap);

void *realloc_itcm_safe(void *ptr, size_t size);

void *calloc_itcm_safe (size_t n, size_t elem_size);

#ifdef __cplusplus
}
#endif

#endif
