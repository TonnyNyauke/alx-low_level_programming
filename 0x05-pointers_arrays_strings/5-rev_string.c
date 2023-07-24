#include "main.h"

/**
 * rev_string - reverses a string
 * @s: pointer to the string
 *
 * Return: nothing.
 */
void rev_string(char *s)
{
	int size = 0;
	int i = 0;
	char temp;

	while (s[size] != '\0')
	{
		size++;
	}

	while (i < size / 2)
	{
		temp = s[i];
		s[i] = s[size - i - 1];
		s[size - i - 1] = temp;
		i++;
	}
}

