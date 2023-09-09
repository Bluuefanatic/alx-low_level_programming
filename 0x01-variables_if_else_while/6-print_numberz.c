#include <unistd.h>

int main(void)
{
	int i;

	i = 48;
	while (i <= 57)
	{
		write(1, &i, 1);
		i++;
	}

	write(1, "\n", 1);

	return (0);
}
