/**
 * rot13 - Encodes a string using rot13
 * @s: The input string
 *
 * Return: A pointer to the modified string
 */
char *rot13(char *s)
{
	char *ptr = s;
	int i;

	while (*s != '\0')
	{
		if ((*s >= 'a' && *s <= 'z') || (*s >= 'A' && *s <= 'Z'))
		{
			for (i = 0; i < 13; i++)
			{
				if ((*s >= 'z' && *s < 'z' + i) || (*s >= 'Z' && *s < 'Z' + i))
				{
					*s = *s - 13 + i;
					break;
				}
				*s = *s + 1;
			}
		}
		s++;
	}
	return (ptr);
}
