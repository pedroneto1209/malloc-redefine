#include <cstddef>
#include <stdint.h>

struct Block_t {
    uint32_t size;
    Block_t *next;
    Block_t *previous;
};

void *malloc_redefine(size_t size);