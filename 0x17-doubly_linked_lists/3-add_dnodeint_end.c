#include "lists.h"
#include <stdlib.h>  /* Include for malloc */

/**
 * add_dnodeint_end - Adds a new node at the end of a dlistint_t list
 * @head: Pointer to a pointer to the head of the doubly linked list
 * @n: Value to be assigned to the new node
 *
 * Return: The address of the new element, or NULL if it failed
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new_node, *temp;

	/* Allocate memory for the new node */
	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);  /* Return NULL if malloc fails */

	/* Assign values to the new node */
	new_node->n = n;
	new_node->next = NULL;

	/* If the list is empty, the new node is the head */
	if (*head == NULL)
	{
		new_node->prev = NULL;
		*head = new_node;
		return (new_node);
	}

	/* Traverse the list to find the last node */
	temp = *head;
	while (temp->next != NULL)
		temp = temp->next;

	/* Update links for the new node at the end */
	temp->next = new_node;
	new_node->prev = temp;

	return (new_node);
}
