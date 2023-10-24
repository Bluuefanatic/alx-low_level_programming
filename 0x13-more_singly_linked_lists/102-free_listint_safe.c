#include "lists.h"
#include <stdlib.h>

/**
 * free_listint_safe - Frees a listint_t linked list safely (handles loops).
 * @h: Pointer to the pointer of the head of the list.
 * Return: The size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *current, *temp;
	size_t count = 0;
	int loop_flag = 0;

	if (h == NULL || *h == NULL)
		return (0);

	current = *h;

	while (current)
	{
		if (loop_flag && current == *h)
		{
			*h = NULL;
			return (count);
		}

		temp = current->next;
		free(current);
		current = temp;

		if (current == *h)
		{
			loop_flag = 1;
		}

		count++;
	}

	*h = NULL;

	return (count);
}
