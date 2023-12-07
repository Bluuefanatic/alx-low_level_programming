#include "lists.h"
#include <stdlib.h>  /* Include for malloc */

/**
 * add_dnodeint - Adds a new node at the beginning of a dlistint_t list
 * @head: Pointer to a pointer to the head of the doubly linked list
 * @n: Value to be assigned to the new node
 *
 * Return: The address of the new element, or NULL if it failed
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new_node;

	/* Allocate memory for the new node */
	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);  /* Return NULL if malloc fails */

	/* Assign values to the new node */
	new_node->n = n;
	new_node->prev = NULL;

	/* Update links */
	if (*head != NULL)
		(*head)->prev = new_node;

	new_node->next = *head;
	*head = new_node;

	return (new_node);
}
