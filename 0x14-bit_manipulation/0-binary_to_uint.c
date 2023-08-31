#include "main.h"

/**
 * binary_to_uint - Converts a binary number to an unsigned int.
 * @b: A pointer to a string containing the binary number.
 *
 * Return: The converted unsigned int, or 0 if there's an invalid character.
 */
unsigned int binary_to_uint(const char *b)
{
	int index = 0;
	unsigned int sum = 0;

	if (b == NULL)
		return (NULL);

	while (b[index] != '\0')
	{
		if (b[index] != '0' && b[index] != '1')
			return (0);

		sum = (sum << 1) + (b[length] - '0');
		length++;
	}

	return (sum);
}

