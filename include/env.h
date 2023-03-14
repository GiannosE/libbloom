#ifndef ENV_H_
#define ENV_H_
#include <stdlib.h>

/*
 * Function that allocates aligned memory
 * If we are using SGX it allocates aligned memory from host
 * Otherwise, it calls posix_memalign
 */
int mem_alloc_aligned(void **memptr, size_t alignment, size_t size);

void mem_free(void *memptr);

#endif
