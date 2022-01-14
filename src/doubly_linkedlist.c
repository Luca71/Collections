#include <stdio.h>
#include "doubly_linkedlist.h"

doub_list_node_t *doubly_get_tail(doub_list_node_t **head_ref)
{
    doub_list_node_t *current_node = *head_ref;
    doub_list_node_t *last_node = NULL;

    while(current_node)
    {
        last_node = current_node;
        current_node = current_node->next;
    }
    return last_node;
}

doub_list_node_t *doubly_append(doub_list_node_t **head, doub_list_node_t *item)
{
    doub_list_node_t *tail = doubly_get_tail(head);
    if(!tail)
    {
        *head = item;
    }
    else
    {
        tail->next = item;
    }

    item->prev = *head;
    item->next = NULL;
    return item;
}

doub_string_item_t *doub_string_item_new(const char *string)
{
    doub_string_item_t *item = malloc(sizeof(doub_string_item_t));
    if(!item)
    {
        return NULL;
    }
    item->string_data = string;
    return item;
}

void doubly_remove(doub_string_item_t **head, const char *key)
{
    doub_string_item_t *temp = *head;
    doub_string_item_t *prev;

    // If head contain key
    if(temp != NULL && temp->string_data == key)
    {
        *head = (doub_string_item_t *)temp->node.next;
        return;
    }

    // search for the key in the whole list nodes
    while(temp != NULL && temp->string_data != key)
    {
        prev = temp;
        temp = (doub_string_item_t *)temp->node.next;
    }

    // if key was not found
    if(temp == NULL)
    {
        printf("The searched element is not in the list.\n");
        return;
    }

    // refactoring nodes link
    prev->node.next = temp->node.next;
    prev->node.prev = temp->node.prev;

    free(temp);
}

void doubly_remove_after_item(doub_string_item_t **head, const char *key)
{
    doub_string_item_t *temp = *head;
    doub_string_item_t *prev;
    doub_string_item_t *item_to_remove;
    doub_string_item_t *item_after_removed_one;

    // If head contain key
    if(temp != NULL && temp->string_data == key)
    {
        item_to_remove = (doub_string_item_t *)temp->node.next;
        item_after_removed_one = (doub_string_item_t *)item_to_remove->node.next;
        (*head)->node.next = (doub_list_node_t *)item_after_removed_one;
        item_after_removed_one->node.prev = (doub_list_node_t *)*head;
        return;
    }

    // search for the key in the whole list nodes
    while(temp != NULL && temp->string_data != key)
    {
        prev = temp;
        temp = (doub_string_item_t *)temp->node.next;
    }

    // if key was not found
    if(temp == NULL)
    {
        printf("The searched element is not in the list.\n");
        return;
    }

    // refactoring nodes link
    item_to_remove = (doub_string_item_t *)temp->node.next;
    item_after_removed_one = (doub_string_item_t *)item_to_remove->node.next;
    temp->node.next = (doub_list_node_t *)item_after_removed_one;

    free(item_to_remove);
}

void doubly_remove_before_item(doub_string_item_t **head, const char *key)
{
    doub_string_item_t *temp = *head;
    doub_string_item_t *prev;
    doub_string_item_t *item_to_remove;
    doub_string_item_t *item_before_removed_one;

    // If head contain key
    if(temp != NULL && temp->string_data == key)
    {
        printf("The are no item before the requested one.\n");
        return;
    }

    // search for the key in the whole list nodes
    while(temp != NULL && temp->string_data != key)
    {
        prev = temp;
        temp = (doub_string_item_t *)temp->node.next;
    }

    // if key was not found
    if(temp == NULL)
    {
        printf("The searched element is not in the list.\n");
        return;
    }

    // refactoring nodes link
    item_to_remove = (doub_string_item_t *)temp->node.prev;

    if((doub_string_item_t *)item_to_remove->node.prev == NULL)
    {
        *head = temp;
        (*head)->node.prev = NULL;
    }
    item_before_removed_one = (doub_string_item_t *)item_to_remove->node.prev;
    temp->node.prev = (doub_list_node_t *)item_before_removed_one;
    item_before_removed_one->node.next = (doub_list_node_t *)temp;

    free(item_to_remove);
}

