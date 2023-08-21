#include "malloc.hpp"
#include "../heap_private.h"
#include <iostream>
#include <stdio.h>

Block_t *createBlockLinkedList(uint32_t numBlocks) {
    Block_t *head = nullptr;
    Block_t *current = nullptr;

    for (uint32_t i = 0; i < numBlocks; ++i) {
        Block_t *newBlock = new Block_t;
        newBlock->size = 1 + (std::rand() % (16));

        if (!head) {
            head = newBlock;
            current = head;
        } else {
            current->next = newBlock;
            newBlock->previous = current;
            current = newBlock;
        }
    }

    return head;
}

Block_t *get_heap() {

    uint16_t caps = (MALLOC_CAP_DEFAULT | MALLOC_CAP_INTERNAL);

    for (int prio = 0; prio < SOC_MEMORY_TYPE_NO_PRIOS; prio++) {
        heap_t *heap;

        SLIST_FOREACH(heap, &registered_heaps, next) {

            if (heap->heap == NULL) {
                continue;
            }

            if ((heap->caps[prio] & caps) != 0) {

                if ((get_all_caps(heap) & caps) == caps) {

                    std::cout << (heap->start) << " to " << (heap->end)
                              << std::endl;

                    uint16_t n_of_blocks = 50 + (std::rand() % (402 - 50 + 1));

                    std::cout << "Number of blocks: " << n_of_blocks
                              << std::endl;

                    return createBlockLinkedList(n_of_blocks);
                }
            }
        }
    }

    return NULL;
}

void print_heap(Block_t *current) {
    while (current->size < 17) {
        std::cout << "Block - Size: " << current->size
                  << ", Next: " << current->next
                  << ", Previous: " << current->previous << std::endl;
        current = current->next;
    }
}

void *malloc_redefine(size_t size) {
    std::cout << "malloc_redefine started" << std::endl;

    if (size > HEAP_SIZE_MAX || size == 0) {
        return NULL;
    }

    Block_t *heap = get_heap();

    print_heap(heap);

    void *ptr = 0x0;
    return ptr;
}
