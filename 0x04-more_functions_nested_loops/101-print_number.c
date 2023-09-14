#include "main.h"

void print_number(int n) {
    int divisor = 1;

    // Handle negative numbers
    if (n < 0) {
        _putchar('-');
        n = -n;
    }

    // Find the largest power of 10 that is less than or equal to n
    while (n / divisor >= 10) {
        divisor *= 10;
    }

    // Print each digit
    while (divisor != 0) {
        _putchar((n / divisor) + '0');
        n %= divisor;
        divisor /= 10;
    }
}

int _putchar(char c) {
    return write(1, &c, 1);
}
