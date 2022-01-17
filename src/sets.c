#include <stdio.h>
#include "sets.h"

size_t djb33x_hash (const char *key, const size_t keylen)
{
    size_t hash = 5381;
    for (size_t i = 0; i < keylen; i++)
    {
        hash =((hash << 5) + hash) ^ key[i];
    }
    return hash;
}

set_table_t *set_table_new (const size_t hashmap_size)
{
    set_table_t *table = malloc(sizeof(set_table_t));
    if(!table)
    {
        return NULL;
    }

    table->hashmap_size = hashmap_size;
    table->nodes = calloc(table->hashmap_size, sizeof(set_table_t *));
    if(!table->nodes)
    {
        free(table);
        return NULL;
    }

    return table;
}

void printTable(set_table_t *table)
{
    for (size_t i = 0; i < table->hashmap_size; i++)
    {
        set_node_t *current_node = table->nodes[i];
        if(current_node)
        {
            printf("%s", table->nodes[i]->key);
            current_node = table->nodes[i]->next;
            while (current_node)
            {
                printf(", %s", current_node->key);
                current_node = current_node->next;
            }
        }
        printf("\n");
    }
}

set_table_t *set_insert (set_table_t *table, const char *key, const size_t key_len)
{
    size_t hash = djb33x_hash(key, key_len);
    size_t index = hash % table->hashmap_size;

    if(set_bool_search(table, key, key_len) == 0)
    {
        printf("\n--- You try to insert %s key, but it already exist in the set!\n", key);
        return (set_table_t *)table;
    }

    set_node_t *head = table->nodes[index];
    if(!head)
    {
        table->nodes[index] = malloc(sizeof(set_node_t));
        if(!table->nodes[index])
        {
            return NULL;
        }
        table->nodes[index]->key = key;
        table->nodes[index]->key_len = key_len;
        table->nodes[index]->next = NULL;

        return (set_table_t *)table->nodes[index];
    }

    set_node_t *new_item = malloc(sizeof(set_node_t));
    if(!new_item)
    {
        return NULL;
    }
    new_item->key = key;
    new_item->key_len = key_len;
    new_item->next = NULL;

    set_node_t *tail = head;
    while (head)
    {
        tail = head;
        head = head->next;
    }
    tail->next = new_item;

    return (set_table_t *)table;
}

void set_search(set_table_t *table, const char *key_to_search, const size_t key_len)
{
    for (size_t i = 0; i < table->hashmap_size; i++)
    {
        set_node_t *current_node = table->nodes[i];
        if(current_node)   /** if node exist **/
        {
            if(current_node->key == key_to_search)
            {
                printf("\'%s\' has been found at index %llu\n\n", key_to_search, i);
                return;
            }

            current_node = table->nodes[i]->next;
            while (current_node)
            {
                if(current_node->key == key_to_search)
                {
                    printf("\'%s\' has been found at index %llu\n\n", key_to_search, i);
                    current_node = NULL;
                    return;
                }
                current_node = current_node->next;
            }
        }
    }
    printf("\'%s\' has not been found!\n", key_to_search);
    printf("\n");
}

int set_bool_search(set_table_t *table, const char *key_to_search, const size_t key_len)
{
    for (size_t i = 0; i < table->hashmap_size; i++)
    {
        set_node_t *current_node = table->nodes[i];
        if(current_node)   /** if node exist **/
        {
            if(current_node->key == key_to_search)
            {
                return 0;
            }

            current_node = table->nodes[i]->next;
            while (current_node)
            {
                if(current_node->key == key_to_search)
                {
                    current_node = NULL;
                    return 0;
                }
                current_node = current_node->next;
            }
        }
    }
    return -1;
}

void set_remove(set_table_t *table, const char *key_to_remove, const size_t key_len)
{
    for (size_t i = 0; i < table->hashmap_size; i++)
    {
        set_node_t *current_node = table->nodes[i];
        if(current_node)   /** if node exist **/
        {
            if(current_node->key == key_to_remove) // libero la memoria del nodo trovato
            {
                if(current_node->next)
                {
                    table->nodes[i] = current_node->next;
                    return;
                }
                table->nodes[i] = NULL;
                return;
            }

            set_node_t *head = table->nodes[i]; // get the head of this index

            current_node = table->nodes[i]->next;
            while (current_node)
            {
                if(current_node->key == key_to_remove) // refactoring the head node
                {
                    if(current_node->next != NULL)
                    {
                        head->next = current_node->next; // refactoring the head next node
                    }
                    head->next = NULL;
                    return;
                }
                current_node = current_node->next;
            }
        }
    }
    printf("The key \'%s\' has not been found in the set\n", key_to_remove);
}
