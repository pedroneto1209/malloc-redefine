#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "malloc.hpp"
#include <stdio.h>

extern "C" {
void app_main();
}

void app_main() {
    printf("Starting code\n");

    void *ptr = malloc_redefine(97);
}