#include <cstddef>
#include <stdint.h>

struct Block_t {
    bool free;
    uint32_t size;
    Block_t *next;
    Block_t *previous;
};

void *malloc_redefine(size_t);
void free_redefine(void *);