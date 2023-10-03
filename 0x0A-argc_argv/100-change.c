#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * min_coins - Calculates the minimum number of coins needed to make change
 *
 * @cents: The amount of cents to be changed
 *
 * Return: The minimum number of coins
 */
int min_coins(int cents)
{
	int coins[] = {25, 10, 5, 2, 1};
	int num_coins = sizeof(coins) / sizeof(coins[0]);
	int num = 0, i = 0;

	while (cents > 0 && i < num_coins)
	{
		if (cents >= coins[i])
		{
			num += cents / coins[i];
			cents %= coins[i];
		}
		i++;
	}

	return (num);
}

/**
 * main - Entry point of the program
 *
 * @argc: The number of command line arguments
 * @argv: An array containing the command line arguments
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
	int cents;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	cents = atoi(argv[1]);

	if (cents < 0)
		printf("0\n");
	else
		printf("%d\n", min_coins(cents));

	return (0);
}
