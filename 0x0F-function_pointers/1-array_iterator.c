/**
 * array_iterator - Executes a function on each element of an array.
 * @array: Pointer to the first element of the array.
 * @size: Number of elements in the array.
 * @action: Pointer to the function to be executed on each element.
 */

#include <stddef.h>

void array_iterator(int *array, size_t size, void (*action)(int))
{
	if (array != NULL && action != NULL)
	{
		size_t i;

		for (i = 0; i < size; i++)
		{
			action(array[i]);
		}
	}
}
