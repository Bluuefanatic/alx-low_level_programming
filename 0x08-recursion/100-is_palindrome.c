#include "main.h"

/**
 * is_palindrome_recursive - Helper function for checking if a string is a pali
 * @s: The string to check.
 * @start: The start index of the string.
 * @end: The end index of the string.
 *
 * Return: 1 if the string is a palindrome, 0 otherwise.
 */
int is_palindrome_recursive(char *s, int start, int end)
{
	if (start >= end)
		return (1);

	if (s[start] != s[end])
		return (0);

	return (is_palindrome_recursive(s, start + 1, end - 1));
}

/**
 * is_palindrome - Returns 1 if a string is a palindrome and 0 if not.
 * @s: The string to check.
 *
 * Return: 1 if the string is a palindrome, 0 otherwise.
 */
int is_palindrome(char *s)
{
	int length = 0;
	int i;

	while (s[length] != '\0')
		length++;

	if (length == 0 || length == 1)
		return (1);

	return (is_palindrome_recursive(s, 0, length - 1));
}
