#include "main.h"

/**
 * get_endianness - Checks the endianness of the system.
 *
 * Return: 0 if big endian, 1 if little endian.
 */
int get_endianness(void)
{
	unsigned int num = 1;
	char *endian_check = (char *)&num;

	/* If the least significant byte is 1, it's little-endian. */
	if (*endian_check == 1)
		return (1); /* Little Endian */

	return (0); /* Big Endian */
}
