#include <stdio.h>

/**
 * print_buffer - Prints the content of a buffer
 * @b: Pointer to the buffer
 * @size: Size of the buffer
 *
 * Description: This function prints the content of a buffer in a specific format.
 */
void print_buffer(char *b, int size)
{
    int i, j;

    if (size <= 0)
    {
        printf("\n");
        return;
    }

    for (i = 0; i < size; i += 10)
    {
        printf("%08x: ", i);

        for (j = 0; j < 10; j++)
        {
            if (i + j < size)
            {
                printf("%02x%02x ", (unsigned char)b[i + j], (unsigned char)b[i + j]);
            }
            else
            {
                printf("     ");
            }
        }

        for (j = 0; j < 10; j++)
        {
            if (i + j < size)
            {
                if (b[i + j] >= 32 && b[i + j] <= 126)
                {
                    printf("%c", b[i + j]);
                }
                else
                {
                    printf(".");
                }
            }
        }

        printf("\n");
    }
}
