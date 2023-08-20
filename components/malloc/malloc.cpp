#include "malloc.hpp"
#include "esp_heap_caps.h"
#include <stdio.h>

extern uint32_t _heap_start;
extern uint32_t _heap_end;

void *malloc_redefine(size_t size) {
    printf("heap start = %x\n", _heap_start);
    printf("heap end = %x\n", _heap_end);

    // extern struct registered_heap_ll registered_heaps;

    // heap_t *heap;
    // SLIST_FOREACH(heap, &registered_heaps, next) {

    //     if (heap->heap == NULL) {
    //         continue;
    //     }
    //     if ((heap->caps[prio] & caps) != 0) {
    //         // Heap has at least one of the caps requested. If caps has other
    //         // bits set that this prio doesn't cover, see if they're
    //         available
    //         // in other prios.
    //         if ((get_all_caps(heap) & caps) == caps) {
    //             // This heap can satisfy all the requested capabilities. See
    //             if
    //             // we can grab some memory using it.
    //             if ((caps & MALLOC_CAP_EXEC) &&
    //                 esp_ptr_in_diram_dram((void *)heap->start)) {
    //                 // This is special, insofar that what we're going to get
    //                 // back is a DRAM address. If so, we need to 'invert' it
    //                 // (lowest address in DRAM == highest address in IRAM and
    //                 // vice-versa) and add a pointer to the DRAM equivalent
    //                 // before the address we're going to return.
    //                 ret = multi_heap_malloc(
    //                     heap->heap, size + 4); // int overflow checked above

    //                 if (ret != NULL) {
    //                     return dram_alloc_to_iram_addr(
    //                         ret, size + 4); // int overflow checked above
    //                 }
    //             } else {
    //                 // Just try to alloc, nothing special.
    //                 ret = multi_heap_malloc(heap->heap, size);
    //                 if (ret != NULL) {
    //                     return ret;
    //                 }
    //             }
    //         }
    //     }
    // }

    // printf("DRAM Memory Dump:\n");

    // for (uint32_t *ptr = &_heap_start; ptr < &_heap_end; ptr++) {
    //     printf("Address: 0x%p, Value: 0x%x\n", ptr, *ptr);
    // }

    void *ptr = 0x0;
    return ptr;
}