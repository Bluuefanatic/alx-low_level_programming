/**
 * string_toupper - Converts all lowercase letters to uppercase
 * @str: The input string
 *
 * Return: A pointer to the modified string
 */
char *string_toupper(char *str)
{
	char *ptr = str;

	while (*ptr != '\0')
	{
		if (*ptr >= 'a' && *ptr <= 'z')
			*ptr -= 32; /* Convert to uppercase */

		ptr++;
	}

	return (str);
}
