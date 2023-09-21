/**
 * rot13 - Encodes a string using rot13
 * @s: The input string
 *
 * Return: A pointer to the modified string
 */
char *rot13(char *s)
{
	char *ptr = s;
	char *alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char *rot13 = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	int i;

	while (*s)
	{
		for (i = 0; i < 52; i++)
		{
			if (*s == alpha[i])
			{
				*s = rot13[i];
				break;
			}
		}
		s++;
	}
	return (ptr);
}
