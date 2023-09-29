#include "main.h"

/**
 * print_binary - Prints the binary representation of an unsigned long int.
 * @n: The unsigned long int to print in binary.
 */
void print_binary(unsigned long int n)
{
	int shift = sizeof(unsigned long int) * 8 - 1;

	if (n == 0)
	{
		_putchar('0');
		return;
	}

	while (shift >= 0)
	{
		if ((n >> shift) & 1)
			_putchar('1');
		else
			_putchar('0');
		shift--;
	}
}
