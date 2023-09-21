#include "main.h"
#include <unistd.h>

/**
 * print_buffer - prints the content of a buffer
 * @b: pointer to the buffer
 * @size: size of the buffer
 *
 * Return: void
 */
void print_buffer(char *b, int size)
{
	int i, j;
	char *line = b;

	if (size <= 0)
	{
		write(1, "\n", 1);
		return;
	}

	for (i = 0; i < size; i += 10)
	{
		printf("%08x: ", i);

		for (j = 0; j < 10; j++)
		{
			if (i + j < size)
				printf("%02x%02x ", (line[i + j] >> 4) & 0xF, line[i + j] & 0xF);
			else
				printf("   ");
		}

		for (j = 0; j < 10; j++)
		{
			if (i + j < size)
			{
				if (line[i + j] >= 32 && line[i + j] <= 126)
					printf("%c", line[i + j]);
				else
					printf(".");
			}
		}

		printf("\n");
	}
}
