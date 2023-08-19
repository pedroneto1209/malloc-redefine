#include "unity.h"
#include <stdio.h>
#include <stdlib.h>

TEST_CASE("Tests function malloc", "[malloc]") {
    void *ptr = malloc(10);
    TEST_ASSERT_NOT_NULL_MESSAGE(ptr, "malloc failed");

    // You can add more assertions or checks on the allocated memory here

    free(ptr);
}
