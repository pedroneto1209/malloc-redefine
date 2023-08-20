#include "malloc.hpp"
#include <stdio.h>

void *malloc_redefine(size_t size) {
    printf("malloc redefine\n");
    void *ptr = 0x0;
    return ptr;
}