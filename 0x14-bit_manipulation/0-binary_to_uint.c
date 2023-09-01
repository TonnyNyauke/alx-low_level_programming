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
	int h = 0;

	if (b == NULL)
		return (0);

	while (b[h] == '0' || b[h] == '1')
	{
		result <<= 1;
		result += b[h] - '0';
		h++;

		if (*b == '0' || *b == '1')
		{
			result <<= 1;
			result += *b - '0';
		}
		else
		{
			return (0);
		}
	}

	if (b[h] != '\0')
		return (0);

	return (result);
}

