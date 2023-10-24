#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_listint_safe - Prints a listint_t linked list safely (handles loops).
 * @head: Pointer to the head of the list.
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *slow = head, *fast = head;
	size_t count = 0;
	int loop_flag = 0;

	while (slow && fast && fast->next)
	{
		if (loop_flag && slow == fast)
		{
			printf("-> [%p] %d\n", (void *)slow, slow->n);
			break;
		}

		printf("[%p] %d\n", (void *)slow, slow->n);

		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
		{
			loop_flag = 1;
			printf("-> [%p] %d\n", (void *)slow, slow->n);
		}

		count++;
	}

	return (count);
}
