#pragma once
#include "clove.h"
#include "dynarray.h"

CLOVE_TEST(DynarrayInitNumberOfElements)
{
    dynarray_t array;
    dynarray_init_type(&array, int);
    CLOVE_UINT_EQ(array.number_of_elements, 0);
}
CLOVE_TEST(DynarrayInitCapacity)
{
    dynarray_t array;
    dynarray_init_type(&array, int);
    CLOVE_UINT_EQ(array.capacity, 4);
}
CLOVE_TEST(DynarrayInitAllocMemory)
{
    dynarray_t array;
    dynarray_init_type(&array, int);
    CLOVE_IS_FALSE(dynarray_init_type(&array, int));
}
CLOVE_TEST(DynarrayAppend)
{
    dynarray_t array;
    dynarray_init_type(&array, int);
    int a = 5;
    dynarray_append(&array, &a);
    CLOVE_INT_EQ(5, array.data[0]);
}
CLOVE_TEST(DynarrayClear)
{
    dynarray_t array;
    dynarray_init_type(&array, int);
    int a = 1, b = 2;
    dynarray_append(&array, &a);
    dynarray_append(&array, &b);
    dynarray_clear(&array);
    CLOVE_UINT_EQ(array.number_of_elements, 0);
    CLOVE_UINT_EQ(array.capacity, 0);
    CLOVE_NULL(array.data);
    CLOVE_NULL(array.tmp_data);
}
CLOVE_TEST(DynarrayGetLen)
{
    dynarray_t array;
    dynarray_init_type(&array, int);
    int a = 5;
    dynarray_append(&array, &a);
    CLOVE_INT_EQ(1, dynarray_len(&array));
}
CLOVE_TEST(DynarrayGetCapacity)
{
    dynarray_t array;
    dynarray_init_type(&array, int);
    int a = 5;
    dynarray_append(&array, &a);
    CLOVE_INT_EQ(4, dynarray_capacity(&array));
}
CLOVE_TEST(DynarrayGetDynamycCapacity)
{
    dynarray_t array;
    dynarray_init_type(&array, int);
    int a = 5;
    int b = 10;
    int c = 4;
    int d = 25;
    int e = 8;
    dynarray_append(&array, &a);
    dynarray_append(&array, &b);
    dynarray_append(&array, &c);
    dynarray_append(&array, &d);
    dynarray_append(&array, &e);
    CLOVE_INT_EQ(5, dynarray_capacity(&array));
}
CLOVE_TEST(DynarrayRemove)
{
    dynarray_t array;
    dynarray_init_type(&array, int);
    int a = 5;
    int b = 10;
    dynarray_append(&array, &a);
    dynarray_append(&array, &b);
    dynarray_remove(&array, 1);
    CLOVE_INT_EQ(1, dynarray_len(&array));
}

/* tests */
CLOVE_SUITE(DynarraySuite)
{
    CLOVE_SUITE_TESTS(
        DynarrayInitNumberOfElements,
        DynarrayInitCapacity,
        DynarrayInitAllocMemory,
        DynarrayAppend,
        DynarrayClear,
        DynarrayGetLen,
        DynarrayGetCapacity,
        DynarrayGetDynamycCapacity,
        DynarrayRemove
    );
}