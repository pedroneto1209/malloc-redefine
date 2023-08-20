#include "malloc.hpp"
#include "unity.h"
#include <stdio.h>
#include <stdlib.h>

TEST_CASE("Tests function malloc", "[malloc]") {
    void *ptr = malloc(10);
    void *ptr2 = malloc_redefine(10);
    TEST_ASSERT_NOT_NULL_MESSAGE(ptr, "malloc failed");
    TEST_ASSERT_NOT_NULL_MESSAGE(ptr2, "malloc_redefine failed");

    TEST_ASSERT_EQUAL(ptr, ptr2);

    // You can add more assertions or checks on the allocated memory here

    free(ptr);
}
