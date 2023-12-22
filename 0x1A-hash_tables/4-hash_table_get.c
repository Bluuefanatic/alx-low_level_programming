#include <stdlib.h>
#include <string.h>
#include "hash_tables.h"

/**
 * hash_table_get - Retrieves the value associated with a key in a hash table
 * @ht: The hash table
 * @key: The key to look for
 *
 * Return: The value associated with the key, or NULL if the key cant be found
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index;
	hash_node_t *current_node;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	/* Get the index for the key using the key_index function */
	index = key_index((const unsigned char *)key, ht->size);

	/* Traverse the linked list at the calculated index */
	current_node = ht->array[index];
	while (current_node != NULL)
	{
		/* If the key is found, return the associated value */
		if (strcmp(current_node->key, key) == 0)
			return (current_node->value);

		current_node = current_node->next;
	}

	/* Key not found */
	return (NULL);
}
