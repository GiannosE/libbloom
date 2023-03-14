#include "env.h"
#include <stdlib.h>
#ifdef SGX
#include <openenclave/enclave.h>
#endif

int mem_alloc_aligned(void **memptr, size_t alignment, size_t size){
  #ifdef SGX
    *memptr = (void*) oe_host_memalign(alignment, size);
    return (*memptr == NULL);
  #else
    return posix_memalign(memptr, alignment, size);
  #endif
}

void mem_free(void *memptr){
  #ifdef SGX
    oe_host_free(memptr);
  #else
    free(memptr);
  #endif
}
