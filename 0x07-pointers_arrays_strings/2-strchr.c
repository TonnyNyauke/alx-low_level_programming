#include "main.h"

/**
 * _strchr - locates a character in a string
 * @s: pointer to the string
 * @c: character to locate
 *
 * Return: pointer to the first occurrence of c in s, or NULL if not found
 */
char *_strchr(char *s, char c)
{
	/* loop through the string until finding c or the null terminator */
	while (*s != '\0')
	{
		/* if c is found, return the pointer to its position */
		if (*s == c)
		{
			return s;
		}
		/* otherwise, move to the next character */
		s++;
	}

	/* if c is the null terminator, return the pointer to it */
	if (c == '\0')
	{
		return s;
	}

	/* if c is not found, return NULL */
	return NULL;
}

