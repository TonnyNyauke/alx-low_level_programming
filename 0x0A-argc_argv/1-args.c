#include "main.h"

/**
 * main - prints the number of arguments passed into it
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 (success)
 */
int main(int argc, char *argv[])
{
	int n = argc - 1;
	int i;

	(void)argv;
	if (n >= 10)
	{
		i = n / 10;
		_putchar(i + '0');
		i = n % 10;
		_putchar(i + '0');
	}
	else
		_putchar(n + '0');
	_putchar('\n');
	return (0);
}
