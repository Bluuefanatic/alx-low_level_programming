#include <stdio.h>

void before_main_message(void)
{
	printf("You're beat! and yet, you must allow,\nI bore my house upon my back!\n");
}

int main(void)
{
	int num1 = 5;
       	int num2 = 7;
       	int sum = num1 + num2;

	before_main_message();

	printf("The sum of %d and %d is %d\n", num1, num2, sum);

	return (0);
}
