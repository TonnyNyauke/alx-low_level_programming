#include "main.h"

/**
 * binary_to_uint - Converts a binary number to an unsigned int.
 * @b: A pointer to a string containing the binary number.
 *
 * Return: The converted unsigned int, or 0 if there's an invalid character.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;

	if (b == NULL)
		return (0);

	int index = 0;
	while (b[index] == '0' || b[index] == '1')
	{
		result <<= 1;
		result += b[index] - '0';
		index++;
	}

	if (b[index] != '\0')
		return (0);

	return (result);
}

