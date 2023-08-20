#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "malloc.hpp"
#include <stdio.h>

extern "C" {
void app_main();
}

void app_main() {
    printf("Hello world!\n");

    void *ptr = malloc_redefine(10);

    for (int i = 1; i >= 0; i--) {
        printf("Restarting in %d seconds...\n", i);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
    printf("Restarting now.\n");
    fflush(stdout);
    esp_restart();
}