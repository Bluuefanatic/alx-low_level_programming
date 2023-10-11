/**
 * print_name - This function prints a name.
 * @name: The name to be printed.
 * @f: A function pointer that takes a char* as an argument.
 */

#include <stdio.h>
#include "function_pointers.h"

void print_name(char *name, void (*f)(char *))
{
	f(name);
}
