#include "main.h"

/**
 * print_binary - Prints the binary representation of an unsigned long int.
 * @n: The unsigned long int to print in binary.
 */
void print_binary(unsigned long int n)
{
	int shift = sizeof(unsigned long int) * 8 - 1;
	int leading_zeros = 0;

	while (shift >= 0)
	{
		if ((n >> shift) & 1 || shift == 0)
		{
			_putchar('0' + ((n >> shift) & 1));
			leading_zeros = 1;
		}
		else if (leading_zeros)
		{
			_putchar('0');
		}
		shift--;
	}
}
