#include "lists.h"
#include <stdlib.h>  /* Include for free */

/**
 * delete_dnodeint_at_index - Deletes the node at a given position in a dlistint_t list
 * @head: Pointer to a pointer to the head of the doubly linked list
 * @index: Index of the node to be deleted
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *temp, *prev;
    unsigned int count = 0;

    if (head == NULL || *head == NULL)
        return -1;  /* Return -1 if the list is empty */

    temp = *head;

    /* If deleting the first node */
    if (index == 0)
    {
        *head = temp->next;
        if (*head != NULL)
            (*head)->prev = NULL;
        free(temp);
        return 1;
    }

    /* Traverse the list to find the position to delete the node */
    while (temp != NULL && count < index)
    {
        prev = temp;
        temp = temp->next;
        count++;
    }

    /* Check if the given index is valid */
    if (temp == NULL)
        return -1;

    /* Update links to delete the node at the specified index */
    prev->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = prev;

    free(temp);
    return 1;
}
