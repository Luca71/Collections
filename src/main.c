#include "dynarray.h"
#include "linkedlist.h"
#include "doubly_linkedlist.h"
#include "sets.h"

#define mylist_append(string_item_t, char) list_append((list_node_t **)string_item_t, (list_node_t *)string_item_new(char))
#define mydoub_list_append(string_item_t, char) doubly_append((doub_list_node_t **)string_item_t, (doub_list_node_t *)doub_string_item_new(char))

int main(void)
{
/*    
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

    // test doubly_linked_list
    doub_string_item_t *my_doub_list = NULL;

    mydoub_list_append(&my_doub_list, "Primo");
    mydoub_list_append(&my_doub_list, "Secondo");
    mydoub_list_append(&my_doub_list, "Terzo");
    mydoub_list_append(&my_doub_list, "Quarto");
    mydoub_list_append(&my_doub_list, "Quinto");

    // print test result
    printf("\n---  Doubly Linked List Test  ---\n\n");
    doub_string_item_t *current_item = my_doub_list;
    while (current_item)
    {
        printf("%s\n", current_item->string_data);
        current_item = (doub_string_item_t*) current_item->node.next;
    }

    printf("\nRimuovo il secondo item della lista. Lista aggiornata:\n\n");
    doubly_remove(&my_doub_list, "Secondo");
    current_item = my_doub_list;
    while (current_item)
    {
        printf("%s\n", current_item->string_data);
        current_item = (doub_string_item_t*) current_item->node.next;
    }

    printf("\nRimuovo elemento dopo il Terzo (Quarto). Lista aggiornata:\n\n");
    doubly_remove_after_item(&my_doub_list, "Terzo");
    current_item = my_doub_list;
    while (current_item)
    {
        printf("%s\n", current_item->string_data);
        current_item = (doub_string_item_t*) current_item->node.next;
    }

    printf("\nRimuovo elemento prima del Quinto (Terzo). Lista aggiornata:\n\n");
    doubly_remove_before_item(&my_doub_list, "Quinto");
    current_item = my_doub_list;
    while (current_item)
    {
        printf("%s\n", current_item->string_data);
        current_item = (doub_string_item_t*) current_item->node.next;
    }
 */

    /*** Test sets ***/
    set_table_t *my_table = set_table_new(5);
    set_insert(my_table, "Prato", 5);
    set_insert(my_table, "Casa", 4);
    set_insert(my_table, "Albero", 6);

    // insert a duplicated key
    printf("Trying to insert \'Albero\' again\n");
    set_insert(my_table, "Albero", 6);

    set_insert(my_table, "Stelle", 6);
    set_insert(my_table, "A", 1);


    // Print the created list
    printf("\n---  The created set  ---\n");
    printTable(my_table);

    // Search for a key
    printf("Search for \'Albero\'\n");
    set_search(my_table, "Albero", 6);
    printf("Search for \'Casa\'\n");
    set_search(my_table, "Casa", 4);
    printf("Search for \'Prato\'\n");
    set_search(my_table, "Prato", 5);
    printf("Search for \'Stalle\'\n");
    set_search(my_table, "Stalle", 6);       // is not in set case
    printf("Search for \'A\'\n");
    set_search(my_table, "A", 1);

    printf("Remove \'A\'\n");                // remove a key from set
    set_remove(my_table, "A", 1);

    printf("\nLa nuova lista:\n");
    printTable(my_table);

    printf("Remove \'Airplane\'\n");                // remove key not in set
    set_remove(my_table, "Airplane", 8);
    
    return 0;
}