#pragma once
#include <stdlib.h>

typedef struct list_node
{
    struct list_node *next;
} list_node_t;

typedef struct string_item
{
    list_node_t node;
    const char *string;
} string_item_t;

/*
* Get the tail of the given list
*
* @param head The head node of the list
*/
list_node_t *list_get_tail(list_node_t **head);

/*
* Append a new item on the given list
*
* @param head The head node of the list
* @param item The new item to append
*/
list_node_t *list_append(list_node_t **head, list_node_t *item);

/*
* Pop the first element of the list
*
* @param head The head node of the list
*/
list_node_t *list_pop(list_node_t **head);

/*
* Create new string item
*
* @param string The new item
*/
string_item_t *string_item_new(const char *string);

/*
* Remove a given item from the list
*
* @param head The head node of the list
* @param string The item to remove
*/
void string_remove(string_item_t **head, const char *string);

