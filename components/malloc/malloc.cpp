#include "malloc.hpp"
#include <stdio.h>

Block_t *get_heap() {
    Block_t *heap = new Block_t[100];

    for (size_t i = 0; i < 100; i++) {
        heap[i].size = i;
    }

    return heap;
}

void *malloc_redefine(size_t size) {
    printf("malloc_redefine started\n");

    Block_t *heap = get_heap();

    printf("heap: ");

    for (size_t i = 0; i < 100; i++) {
        printf("%x, ", heap[i].size);
    }

    void *ptr = 0x0;
    return ptr;
}
