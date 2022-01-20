#pragma once
#include <stdlib.h>

typedef struct doub_list_node
{
    int data;
    struct doub_list_node *next;
    struct doub_list_node *prev;
} doub_list_node_t;

typedef struct doub_string_item
{
    doub_list_node_t node;
    const char *string_data;
} doub_string_item_t;

/*
* Get the tail of the given list
*
* @param head_ref The head node of the list
*/
doub_list_node_t *doubly_get_tail(doub_list_node_t **head_ref);

/*
* Append a new item on the given list
*
* @param head The head node of the list
* @param item The new item to append
*/
doub_list_node_t *doubly_append(doub_list_node_t **head, doub_list_node_t *item);

/*
* Create new string item
*
* @param string The new item
*/
doub_string_item_t *doub_string_item_new(const char *string);

/*
* Remove a given item from the list
*
* @param head The head node of the list
* @param key The item to remove
*/
void doubly_remove(doub_string_item_t **head, const char *key);

/*
* Remove from the list the element after the given item
*
* @param head The head node of the list
* @param key The item before the element to remove
*/
void doubly_remove_after_item(doub_string_item_t **head, const char *key);

/*
* Remove from the list the element before the given item
*
* @param head The head node of the list
* @param key The item after the element to remove
*/
void doubly_remove_before_item(doub_string_item_t **head, const char *key);




