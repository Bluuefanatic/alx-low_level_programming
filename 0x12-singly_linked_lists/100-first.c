#include <stdio.h>

void before_main(void);

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	before_main();
	return (0);
}

/**
 * before_main - Prints a message before main
 */
void before_main(void)
{
	printf("You're beat! and yet, you must allow,\nI bore my house upon my back!\n");
}
