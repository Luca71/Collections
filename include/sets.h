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

/*
* Basic hash algorithm
*
* @param key The key you need to hash
* @param keylen The length of the given key
*/
size_t djb33x_hash (const char *key, const size_t keylen);

/*
* Create new table for the set
*
* @param hasmap_size The size of the hash map
*/
set_table_t *set_table_new (const size_t hashmap_size);

/*
* Print the table content in console
*
* @param table The table to print
*/
void printTable(set_table_t *table);

/*
* Insert a new value in the table of the set
*
* @param table My table
* @param key The new item to insert
* @param keylen The length of the given key
*/
set_table_t *set_insert (set_table_t *table, const char *key, const size_t key_len);

/*
* Print in console if the given key was found and its index
*
* @param table My table
* @param key_to_search The item to search
* @param keylen The length of the given key
*/
void set_search(set_table_t *table, const char *key_to_search, const size_t key_len);

/*
* Remove the given key from the table of the set
*
* @param table My table
* @param key_to_remove The item to remove
* @param keylen The length of the given key
*/
void set_remove(set_table_t *table, const char *key_to_remove, const size_t key_len);