#include "dynarray.h"

int dynarray_init(dynarray_t *array, const size_t size_of_element)
{
    array->number_of_elements = 0;
    array->size_of_element = size_of_element;
    array->capacity = 4;                                            // init capacity to 4 as per rotator struct
    array->data = malloc(size_of_element * array->capacity);        // create memory space for capacity
    if(!array->data)
    {
        return -1;
    }
    array->tmp_data = malloc(size_of_element);    
    if(!array->tmp_data)
    {
        return -1;
    }
    return 0;
}

void dynarray_clear(dynarray_t *array)
{
    array->number_of_elements = 0;
    array->capacity = 0;
    free(array->data);                  // free memory
    array->data = NULL;                 // clear the pointer inside data
    free(array->tmp_data);
    array->tmp_data = NULL;
}

int dynarray_append(dynarray_t *array, const void *value)
{
    const size_t new_size = array->number_of_elements + 1;

    // if elements num is bigger then current capacity
    if(new_size > array->capacity)                                                      
    {
        uint8_t *new_ptr = realloc(array->data, new_size * array->size_of_element);
        if(!new_ptr)
        {
            return -1;
        }
        array->data = new_ptr;
        array->capacity += 1;       // increment current capacity
    }

    size_t offset = array->number_of_elements * array->size_of_element;
    memcpy(array->data + offset, value, array->size_of_element);
    array->number_of_elements = new_size;
    return 0;
}

size_t dynarray_len(const dynarray_t *array)
{
    return array->number_of_elements;
}

size_t dynarray_capacity(const dynarray_t *array)
{
    return array->capacity;
}

int dynaray_get(const dynarray_t *array, const size_t index, void *value)
{
    if(index >= array->number_of_elements)
    {
        return -1;
    }

    const size_t offset = index * array->size_of_element;
    memcpy(value, array->data + offset, array->size_of_element);
    return 0;
}

int dynarray_remove(dynarray_t *array, const size_t index)
{
    if(index >= array->number_of_elements)
    {
        return -1;
    }

    const size_t offset = index * array->size_of_element;
    if(index < array->number_of_elements - 1)
    {
        memcpy(array->tmp_data, array->data + offset, array->size_of_element); // make copy if the original data will be lost
        memmove(array->data + offset, array->data + offset + array->size_of_element, (array->number_of_elements - index) * array->size_of_element);
    }

    const size_t new_size = array->number_of_elements - 1;
    // decrease memory size if elements <= 4
    if(new_size <= 4)                                                                       
    {
        array->capacity = 4;
        uint8_t *new_ptr = realloc(array->data, array->capacity * array->size_of_element);
        if(!new_ptr)
        {
            // restore the original condition
            if(index < array->number_of_elements - 1)
            {
                memmove(array->data + offset + array->size_of_element, array->data + offset, (array->number_of_elements - index) * array->size_of_element);
                memcpy(array->data + offset, array->tmp_data, array->size_of_element); // restore the original data
            }
            return -1;
        }

        array->data = new_ptr;
    }

    array->number_of_elements = new_size;
    return 0;
}