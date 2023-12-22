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
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0')
		return (0);

	index = key_index((const unsigned char *)key, ht->size);

	return (add_node_at_index(&(ht->array[index]), key, value));
}

/**
 * add_node_at_index - Adds a node at the beginning of a linked list
 * @head: Pointer to the head of the linked list
 * @key: The key
 * @value: The value associated with the key
 *
 * Return: 1 if successful, 0 otherwise
 */
int add_node_at_index(hash_node_t **head, const char *key, const char *value)
{
	hash_node_t *new_node;

	new_node = create_node(key, value);
	if (new_node == NULL)
		return (0);

	new_node->next = *head;
	*head = new_node;

	return (1);
}

/**
 * create_node - Creates a new hash node
 * @key: The key
 * @value: The value associated with the key
 *
 * Return: A pointer to the new node, or NULL if an error occurs
 */
hash_node_t *create_node(const char *key, const char *value)
{
	hash_node_t *new_node;

	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
		return (NULL);

	new_node->key = strdup(key);
	new_node->value = strdup(value);

	if (new_node->key == NULL || new_node->value == NULL)
	{
		free(new_node->key);
		free(new_node->value);
		free(new_node);
		return (NULL);
	}

	return (new_node);
}
