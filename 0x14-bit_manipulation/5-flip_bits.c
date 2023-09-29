#include "main.h"

/**
 * flip_bits - Calculates the number of
 * bits to flip from one number to another.
 * @n: The first unsigned long int number.
 * @m: The second unsigned long int number.
 *
 * Return: The number of bits to flip.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int xor_result = n ^ m;
	unsigned int count = 0;

	while (xor_result > 0)
	{
		count += xor_result & 1;
		xor_result >>= 1;
	}

	return (count);
}
