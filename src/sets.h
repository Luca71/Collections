#pragma once
#include <stdlib.h>

typedef struct set_node
{
    const char *key;
    size_t key_len;
    struct set_node *next;
} set_node_t;

typedef struct set_table
{
    struct set_node **nodes;
    size_t hashmap_size;
} set_table_t;

size_t djb33x_hash (const char *key, const size_t keylen);
set_table_t *set_table_new (const size_t hasmap_size);
void printTable(set_table_t *table);
set_table_t *set_insert (set_table_t *table, const char *key, const size_t key_len);
void set_search(set_table_t *table, const char *key_to_search, const size_t key_len);
int set_bool_search(set_table_t *table, const char *key_to_search, const size_t key_len);
void set_remove(set_table_t *table, const char *key_to_remove, const size_t key_len);