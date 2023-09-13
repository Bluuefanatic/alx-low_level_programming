#include "main.h"

int main(void)
{
    int num = 12345;
    int last_digit = print_last_digit(num);
    _putchar('\n');
    _putchar('0' + last_digit);
    return 0;
}
