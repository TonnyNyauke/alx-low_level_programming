#include "main.h"

/**
 * binary_to_uint - Converts a binary number to an unsigned int.
 * @b: A pointer to a string containing 0s and 1s.
 *
 * Return: The converted number, or 0 if there are invalid characters
 * or if b is NULL.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;
	int leading_zeros = 1;

	if (b == NULL)
		return (0);

	while (*b)
	{
		if (*b != '0' && *b != '1')
			return (0);

		if (*b == '1')
			leading_zeros = 0;
		if (!leading_zeros)
			result = result * 2 + (*b - '0');
		b++;
	}

	return (result);
}

