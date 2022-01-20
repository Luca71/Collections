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

/*
* Inizialization of the array
*
* @param array My new array
* @param size_of_element Size for the array elements
*/
int dynarray_init(dynarray_t *array, const size_t size_of_element);

/*
* Clear the array and his memory
*
* @param array The array to clear
*/
void dynarray_clear(dynarray_t *array);

/*
* Append new value into the array
*
* @param array My array
* @param value The new value to append
*/
int dynarray_append(dynarray_t *array, const void *value);

/*
* Get the length of the given array
*
* @param array My Array
*/
size_t dynarray_len(const dynarray_t *array);

/*
* Get the capacity of the given array (Number of elements)
*
* @param array My array
*/
size_t dynarray_capacity(const dynarray_t *array);

/*
* Get array value at specific index
*
* @param array My array
* @param index The index of the value in the array
* @param value The returned value
*/
int dynaray_get(const dynarray_t *array, const size_t index, void *value);

/*
* Remove an item from the array
*
* @param array My array
* @param index The index of the item to remove
*/
int dynarray_remove(dynarray_t *array, const size_t index);