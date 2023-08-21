#include "malloc.hpp"
#include "unity.h"
#include <stdio.h>
#include <stdlib.h>

// This should test if both functions has the same results, this test is only
// for demonstration as the functions are not fully implemented yet
TEST_CASE("Tests function malloc", "[malloc]") {
    void *ptr = malloc(10);
    free(ptr);
    void *ptr2 = malloc_redefine(10);
    free_redefine(ptr2);

    TEST_ASSERT_NOT_NULL_MESSAGE(ptr, "malloc failed");
    TEST_ASSERT_NOT_NULL_MESSAGE(ptr2, "malloc_redefine failed");

    TEST_ASSERT_EQUAL(ptr, ptr2);

    free(ptr);
}
