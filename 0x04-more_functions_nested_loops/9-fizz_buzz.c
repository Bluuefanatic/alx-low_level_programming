#include <unistd.h>

/**
 * main - Entry point of the program
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    int i;

    for (i = 1; i <= 100; i++)
    {
        if (i % 3 == 0 && i % 5 == 0)
        {
            write(1, "FizzBuzz", 8);
        }
        else if (i % 3 == 0)
        {
            write(1, "Fizz", 4);
        }
        else if (i % 5 == 0)
        {
            write(1, "Buzz", 4);
        }
        else
        {
            int temp, digits, div;

            digits = 0;
            temp = i;

            while (temp)
            {
                temp /= 10;
                digits++;
            }

            while (digits > 0)
            {
                temp = i;
                div = 1;
                digits--;

                while (digits > 0)
                {
                    temp /= 10;
                    div *= 10;
                    digits--;
                }

                char c = (temp % 10) + '0';
                write(1, &c, 1);
            }
        }

        if (i != 100)
            write(1, " ", 1);
        else
            write(1, "\n", 1);
    }

    return (0);
}
