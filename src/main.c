#include "dynarray.h"
#include "linkedlist.h"

#define mylist_append(string_item_t, char) list_append((list_node_t **)string_item_t, (list_node_t *)string_item_new(char))

int main()
{
    
    // dynarray test
    dynarray_t array;
    dynarray_init_type(&array, int);

    int a = 1;
    int b = 2;
    int c = 3;
    int d = 4;
    int e = 5;
    int f = 6;

    dynarray_append(&array, &a);
    dynarray_append(&array, &b);
    dynarray_append(&array, &c);
    dynarray_append(&array, &d);
    dynarray_append(&array, &e);
    dynarray_append(&array, &f);

    printf("Number of elements = %llu\n", dynarray_len(&array));
    printf("Capacity of the array = %llu\n", dynarray_capacity(&array));
    
    for (size_t i = 0; i < dynarray_len(&array); i++)
    {
        int value;
        if(!dynaray_get(&array, i, &value))
        {
            printf("[%llu] %d\n", i, value);
        }
    }

    printf("Remove 2 elements!-------------------------------------\n");
    dynarray_remove(&array, 0);
    dynarray_remove(&array, 0);

    printf("Number of elements = %llu\n", dynarray_len(&array));
    printf("Capacity of the array = %llu\n", dynarray_capacity(&array));

    for (size_t i = 0; i < dynarray_len(&array); i++)
    {
        int value;
        if(!dynaray_get(&array, i, &value))
        {
            printf("[%llu] %d\n", i, value);
        }
    }

    dynarray_clear(&array);
    printf("\n");

    // linked list test
    string_item_t *my_linked_list = NULL;

    mylist_append(&my_linked_list, "Hello World");
    mylist_append(&my_linked_list, "Test001");
    mylist_append(&my_linked_list, "Test002");
    mylist_append(&my_linked_list, "Last Item of the Linked List");

    struct string_item *string_item = my_linked_list;

    while (string_item)
    {
        printf("%s\n", string_item->string);
        string_item = (struct string_item *)string_item->node.next;
    }

    //string_remove(&my_linked_list, "Hello World");
    string_remove(&my_linked_list, "Test002");

    string_item = my_linked_list;
    while (string_item)
    {
        printf("%s\n", string_item->string);
        string_item = (struct string_item *)string_item->node.next;
    }





    return 0;
}