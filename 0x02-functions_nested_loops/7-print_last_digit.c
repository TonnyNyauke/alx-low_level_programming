#include "main.h"

/**
 * print_last_digit - prints the last digit of a number
 * @n: the number to print
 * Return: the last digit
 */
int print_last_digit(int n)
{
	int last = _abs(n) % 10;
	_putchar(last + '0');
	return (last);
}

