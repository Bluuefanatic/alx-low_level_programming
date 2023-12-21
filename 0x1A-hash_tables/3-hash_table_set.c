#include <stdlib.h>
#include <string.h>
#include "hash_tables.h"

/**
 * hash_table_set - Adds an element to the hash table
 * @ht: The hash table
 * @key: The key
 * @value: The value associated with the key
 *
 * Return: 1 if successful, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
    hash_node_t *new_node, *current_node;
    unsigned long int index;

    if (ht == NULL || key == NULL || *key == '\0')
        return (0);

    /* Get the index for the key using the key_index function */
    index = key_index((const unsigned char *)key, ht->size);

    /* Check if the key already exists in the linked list at the index */
    current_node = ht->array[index];
    while (current_node != NULL)
    {
        /* If the key exists, update the value and return success */
        if (strcmp(current_node->key, key) == 0)
        {
            free(current_node->value);
            current_node->value = strdup(value);
            if (current_node->value == NULL)
                return (0);
            return (1);
        }
        current_node = current_node->next;
    }

    /* Key doesn't exist, create a new node and add it to the linked list */
    new_node = malloc(sizeof(hash_node_t));
    if (new_node == NULL)
        return (0);

    new_node->key = strdup(key);
    new_node->value = strdup(value);
    if (new_node->key == NULL || new_node->value == NULL)
    {
        free(new_node->key);
        free(new_node->value);
        free(new_node);
        return (0);
    }

    /* Add the new node at the beginning of the linked list */
    new_node->next = ht->array[index];
    ht->array[index] = new_node;

    return (1);
}
