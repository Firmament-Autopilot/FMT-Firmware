#include <errno.h>
#include <stdint.h>
#include <stdlib.h>

extern void *memalign(size_t alignment, size_t size);

int posix_memalign(void **memptr, size_t alignment, size_t size)
{
    void *ptr;

    if (alignment < sizeof(void *) ||
        (alignment & (alignment - 1)) != 0) {
        return EINVAL;
    }

    ptr = memalign(alignment, size);
    if (ptr == NULL) {
        return ENOMEM;
    }

    *memptr = ptr;
    return 0;
}
