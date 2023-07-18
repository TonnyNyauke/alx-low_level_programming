#include "main.h"

/**
 * print_alphabet_x10 -  a function that prints 10 times the alphabet,
 *  in lowercase, followed by a new line.
 */
void print_alphabet_x10(void)
{
	int n = 0;
	char c;

	while (n < 10)
	{
		for (c = 'a'; c <= 'z'; c++)
		{
			_putchar(c);
		}
		_putchar('\n');
		n++;
	}
}
