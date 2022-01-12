#pragma once
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#define dynarray_init_type(array, type) dynarray_init(array, sizeof(type))

typedef struct dynarray
{
    size_t number_of_elements;      // size of array
    size_t size_of_element;         // type of array element
    size_t capacity;                // array capacity                
    uint8_t *data;                  // memory address
    uint8_t *tmp_data;
} dynarray_t;

int dynarray_init(dynarray_t *array, const size_t size_of_element);
void dynarray_clear(dynarray_t *array);
int dynarray_append(dynarray_t *array, const void *value);

size_t dynarray_len(const dynarray_t *array);
size_t dynarray_capacity(const dynarray_t *array);
int dynaray_get(const dynarray_t *array, const size_t index, void *value);
int dynarray_remove(dynarray_t *array, const size_t index);