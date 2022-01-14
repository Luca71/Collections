#include "linkedlist.h"
#include <stdio.h>

list_node_t *list_get_tail(list_node_t **head)
{
    list_node_t *current_node = *head;
    list_node_t *last_node = NULL;

    while(current_node)
    {
        last_node = current_node;
        current_node = current_node->next;
    }

    return last_node;
}

list_node_t *list_append(list_node_t **head, list_node_t *item)
{
    list_node_t *tail = list_get_tail(head);
    if(!tail)
    {
        *head = item;
    }
    else
    {
        tail->next = item;
    }

    item->next = NULL;
    return item;
}

list_node_t *list_pop(list_node_t **head)
{
    list_node_t *current_head = *head;
    if(!current_head)
    {
        return NULL;
    }
    
    *head = (*head)->next;
    current_head->next = NULL;

    return current_head;
}

string_item_t *string_item_new(const char *string)
{
    string_item_t *item = malloc(sizeof(string_item_t));
    if(!item)
    {
        return NULL;
    }
    item->string = string;
    return item;
}

void string_remove(string_item_t **head, const char *key)
{
    string_item_t *temp = *head;
    string_item_t *prev;

    // If head contain key
    if(temp != NULL && temp->string == key)
    {
        *head = (struct string_item *)temp->node.next;
        return;
    }

    // search for the key in the whole list nodes
    while(temp != NULL && temp->string != key)
    {
        prev = temp;
        temp = (struct string_item *)temp->node.next;
    }

    // if key was not found
    if(temp == NULL)
    {
        printf("The searched element is not in the list.\n");
        return;
    }

    // refactoring nodes link
    prev->node.next = temp->node.next;

    free(temp);
}


