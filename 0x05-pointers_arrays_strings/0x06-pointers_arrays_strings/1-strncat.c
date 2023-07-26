#include "main.h"

/**
 * _strncat - concatenates two strings with a limit
 * @dest: destination string
 * @src: source string
 * @n: maximum number of bytes to use from src
 *
 * Return: pointer to resulting string dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, j;

	/* Find the end of the destination string */
	for (i = 0; dest[i] != '\0'; i++)
		;

	/* Append n bytes from the source string to the destination string */
	for (j = 0; j < n && src[j] != '\0'; j++)
	{
		dest[i + j] = src[j];
	}

	/* Add null terminator */
	dest[i + j] = '\0';

	return (dest);
}

