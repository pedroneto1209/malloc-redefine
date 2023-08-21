#include "malloc.hpp"
#include "../heap_private.h"
#include <iostream>
#include <stdio.h>

Block_t *heap_head;

Block_t *createBlockLinkedList(uint32_t numBlocks) {
    Block_t *head = nullptr;
    Block_t *current = nullptr;

    for (uint32_t i = 0; i < numBlocks; ++i) {
        Block_t *newBlock = new Block_t;
        newBlock->size = 1 + (std::rand() % (128));

        if ((std::rand() % (101)) > 50) {
            newBlock->free = 0;
        } else {
            newBlock->free = 1;
        }

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

                    return createBlockLinkedList(100);
                }
            }
        }
    }

    return NULL;
}

void print_heap(Block_t *current) {
    size_t i = 0;
    while (current->size < 129) {
        std::cout << i << ": "
                  << "Block - Size: " << current->size
                  << ", Next: " << current->next
                  << ", Previous: " << current->previous
                  << ", Free: " << current->free << std::endl;
        current = current->next;
        i++;
    }
}

Block_t *find_best_block(Block_t *current, size_t size) {

    Block_t *min_size_block = nullptr;
    size_t min_size = 128;

    while (current->size < 129) {
        if (current->free && current->size > size) {

            if (current->size == size) {
                std::cout << "Best block is: " << current->size
                          << ", Next: " << current->next
                          << ", Previous: " << current->previous
                          << ", Free: " << current->free << std::endl;

                return current;
            }

            if (current->size < min_size) {
                min_size = current->size;
                min_size_block = current;
            }
        }
        current = current->next;
    }

    if (min_size_block != nullptr) {
        std::cout << "Best block is: " << min_size_block->size
                  << ", Next: " << min_size_block->next
                  << ", Previous: " << min_size_block->previous
                  << ", Free: " << min_size_block->free << std::endl;
    }

    return min_size_block;
}

void *alloc_block(Block_t *best_block, size_t size) {
    void *ptr;

    if (best_block->size == size) {
        best_block->free = 0;
        ptr = &best_block;
    } else {
        Block_t *new_block = new Block_t;

        new_block->size = best_block->size - size;
        new_block->free = 1;
        new_block->next = best_block->next;
        new_block->previous = best_block;

        best_block->size = size;
        best_block->free = 0;
        best_block->next = new_block;

        ptr = &best_block;
    }

    return ptr;
}

void *malloc_redefine(size_t size) {
    std::cout << "malloc_redefine started" << std::endl;

    if (size > HEAP_SIZE_MAX || size == 0) {
        return NULL;
    }

    heap_head = get_heap();

    print_heap(heap_head);

    Block_t *best_block = find_best_block(heap_head, size);

    alloc_block(best_block, size);

    print_heap(heap_head);

    return best_block;
}

void free_redefine(void *ptr) {
    std::cout << "free_redefine started" << std::endl;
    Block_t *block = (Block_t *)ptr;

    std::cout << block->next << std::endl;

    block->free = 1;

    if (block->previous->free) {
        block->previous->previous->next = block;
        block->previous = block->previous->previous;
        block->size += block->previous->size;
    }

    if (block->next->free) {
        block->next->next->previous = block;
        block->next = block->next->next;
        block->size += block->next->size;
    }

    print_heap(heap_head);
}