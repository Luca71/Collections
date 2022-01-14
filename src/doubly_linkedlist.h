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

// doub_list_node_t list_append(doub_list_node_t **head_ref, int new_data);

doub_list_node_t *doubly_get_tail(doub_list_node_t **head_ref);
doub_list_node_t *doubly_append(doub_list_node_t **head, doub_list_node_t *item);
doub_string_item_t *doub_string_item_new(const char *string);
void doubly_remove(doub_string_item_t **head, const char *key);
void doubly_remove_after_item(doub_string_item_t **head, const char *key);
void doubly_remove_before_item(doub_string_item_t **head, const char *key);




