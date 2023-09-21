/**
 * cap_string - Capitalizes all words of a string
 * @str: The input string
 *
 * Return: A pointer to the modified string
 */
char *cap_string(char *str)
{
	char *ptr = str;
	int capitalize = 1;

	while (*ptr != '\0')
	{
		if (*ptr >= 'a' && *ptr <= 'z')
		{
			if (capitalize)
			{
				*ptr -= 32; /* Convert to uppercase */
				capitalize = 0;
			}
		}
		else
		{
			if (*ptr == ' ' || *ptr == '\t' || *ptr == '\n'
				|| *ptr == ',' || *ptr == ';' || *ptr == '.'
				|| *ptr == '!' || *ptr == '?' || *ptr == '"'
				|| *ptr == '(' || *ptr == ')' || *ptr == '{'
				|| *ptr == '}')
			{
				capitalize = 1;
			}
		}

		ptr++;
	}

	return (str);
}
