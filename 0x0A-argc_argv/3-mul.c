#include "main.h"

/**
 * main - multiplies two numbers
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 (success), 1 (error)
 */
int main(int argc, char *argv[])
{
	int a, b, result;

	if (argc != 3)
	{
		char *error = "Error\n";
		int i;

		for (i = 0; error[i] != '\0'; i++)
			_putchar(error[i]);
		return (1);
	}
	a = _atoi(argv[1]);
	b = _atoi(argv[2]);
	result = a * b;
	print_number(result);
	_putchar('\n');
	return (0);
}
