#include "dog.h"
#include <stdio.h>

/**
 * print_dog - Prints the information of a dog
 * @d: Pointer to the struct dog
 *
 * Description: If an element of d is NULL, print (nil) instead of this element
 * (if name is NULL, print Name: (nil)). If d is NULL print nothing.
 */
void print_dog(struct dog *d)
{
	if (d)
	{
		printf("Name: %s\n", d->name ? d->name : "(nil)");
		printf("Age: %f\n", d->age);
		printf("Owner: %s\n", d->owner ? d->owner : "(nil)");
	}
}
