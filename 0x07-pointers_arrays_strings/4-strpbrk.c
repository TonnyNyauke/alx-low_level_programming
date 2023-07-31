#include "main.h"

/**
 * _strpbrk - searches a string for any of a set of bytes
 * @s: pointer to the string
 * @accept: pointer to the set of bytes
 *
 * Return: pointer to the byte in s that matches one of the bytes in accept, or NULL if not found
 */
char *_strpbrk(char *s, char *accept)
{
	unsigned int i, j;

	/* loop through the string s */
	for (i = 0; s[i] != '\0'; i++)
	{
		/* loop through the set of bytes accept */
		for (j = 0; accept[j] != '\0'; j++)
		{
			/* if the current character of s matches any character of accept */
			if (s[i] == accept[j])
			{
				/* return the pointer to the matching character in s */
				return s + i;
			}
		}
	}

	/* if no match is found, return NULL */
	return NULL;
}

