#include "lists.h"
#include <stdlib.h>

/**
 * free_list - frees a list_t list
 * @head: pointer to the head of the list
 */
void free_list(list_t *head)
{
	list_t *next = NULL;

	while (head != NULL)
	{
		next = head->next;
		free(head);
		head = next;
	}
}

