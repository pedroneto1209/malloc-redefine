#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "malloc.hpp"
#include <stdio.h>

extern "C" {
void app_main();
}

void app_main() {
    printf("Starting code\n");

    void *ptr = malloc_redefine(10);
    void *ptr_malloc = malloc(10);
    void *ptr2 = malloc_redefine(10);
}