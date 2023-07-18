#include "main.h"

/**
 * print_last_digit -  a function that prints the last digit of a number.
 *
 * Return: the last digit of the number
 */
int print_last_digit(int n)
{
	int num = n%10;
	if(num<0)
	{
		num = -num;
	}
	_putchar(num);

	return (num);
}
