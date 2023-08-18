#include <stdio.h>
#include <stdlib.h>
#include <unity.h>

void setUp(void) {}

void tearDown(void) {}

void test_malloc(void) {
    size_t size = 10;
    void *ptr = malloc(size);
    TEST_ASSERT_NOT_NULL_MESSAGE(ptr, "malloc failed");

    free(ptr);
}

void app_main() {
    UNITY_BEGIN();
    RUN_TEST(test_malloc);
    UNITY_END();
}
