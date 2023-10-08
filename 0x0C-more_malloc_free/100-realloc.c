#include "main.h"
#include <stdlib.h>

/**
 * _realloc - Reallocates a memory block using malloc and free
 * @ptr: Pointer to the memory previously allocated with malloc
 * @old_size: Size in bytes of the allocated space for ptr
 * @new_size: New size in bytes of the new memory block
 *
 * Return: Pointer to the newly allocated memory block
 *         NULL if malloc fails or new_size is 0 and ptr is not NULL
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
    char *new_ptr, *old_ptr;
    unsigned int i;

    if (new_size == old_size)
        return (ptr);

    if (ptr == NULL)
        return (malloc(new_size));

    if (new_size == 0)
    {
        free(ptr);
        return (NULL);
    }

    new_ptr = malloc(new_size);

    if (new_ptr == NULL)
        return (NULL);

    old_ptr = ptr;

    for (i = 0; i < old_size && i < new_size; i++)
        new_ptr[i] = old_ptr[i];

    free(ptr);

    return (new_ptr);
}
