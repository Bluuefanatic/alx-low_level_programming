#include "main.h"


/**
 * sum_of_multiples - Calculates the sum of multiples of 3 or 5 below 1024.
 *
 * This function iterates through numbers below 1024 and adds those that are
 * multiples of either 3 or 5 to the total sum.
 *
 * Return: The sum of multiples.
 */
int sum_of_multiples(void)
{
    int sum = 0;
    
    for (int i = 0; i < 1024; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            sum += i;
        }
    }

    return sum;
}
