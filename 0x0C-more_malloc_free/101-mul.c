#include "main.h"

/**
 * _isdigit - checks if a character is a digit
 * @c: character to check
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - returns the length of a string
 * @s: string to check
 *
 * Return: length of s
 */
int _strlen(char *s)
{
	int len;

	for (len = 0; s[len] != '\0'; len++)
		;

	return (len);
}

/**
 * _puts - prints a string, followed by a new line
 * @str: string to print
 */
void _puts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
	_putchar('\n');
}

/**
 * error - prints an error message and exits with a status of 98
 */
void error(void)
{
	_puts("Error");
	exit(98);
}

/**
 * multiply - multiplies two positive numbers and prints the result
 * @num1: first number
 * @num2: second number
 */
void multiply(char *num1, char *num2)
{
	int len1, len2, len, carry, i, j, k;
	int *result;

	/* get the lengths of the numbers */
	len1 = _strlen(num1);
	len2 = _strlen(num2);

	/* allocate memory for the result */
	len = len1 + len2;
	result = calloc(len, sizeof(int));
	if (result == NULL)
		error();

	/* multiply the numbers */
	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			result[i + j + 1] += (num1[i] - '0') * (num2[j] - '0') + carry;
			carry = result[i + j + 1] / 10;
			result[i + j + 1] %= 10;
		}
		result[i + j + 1] += carry;
	}

	/* print the result */
	k = result[0] == 0 ? 1 : 0;
	for (; k < len; k++)
		_putchar(result[k] + '0');
	_putchar('\n');

	/* free memory */
	free(result);
}

/**
 * main - multiplies two positive numbers
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char **argv)
{
	int i;

	/* check number of arguments */
	if (argc != 3)
		error();

	/* check if arguments are digits */
	for (i = 1; i < argc; i++)
		if (!(_isdigit(argv[i][0]) || (_strlen(argv[i]) > 1 && argv[i][0] == '-' && _isdigit(argv[i][1]))))
			error();

	/* multiply the numbers */
	multiply(argv[1], argv[2]);

	return (0);
}
