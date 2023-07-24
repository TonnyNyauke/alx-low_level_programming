#include "main.h"

/**
 * print_rev - prints a string, in reverse, followed by a new line
 * @s: pointer to the string
 *
 * Return: nothing
 */
void print_rev(char *s)
{
	int size = 0;

	while (s[size] != '\0')
	{
		size++;
	}
	while (size > 0)
	{
		_putchar(s[size - 1]);
		size--;
	}
	_putchar('\n');
}
