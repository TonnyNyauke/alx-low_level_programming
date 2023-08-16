#include "function_pointers.h"

/**
 * print_number - prints an integer
 * @n: integer to print
 */
void print_number(int n)
{
	unsigned int num;

	if (n < 0)
	{
		_putchar('-');
		num = -n;
	}
	else
        num = n;
    if (num / 10)
        print_number(num / 10);
    _putchar((num % 10) + '0');
}

/**
 * print_hex - prints a number in hexadecimal
 * @n: number to print
 */
void print_hex(unsigned int n)
{
    if (n / 16)
        print_hex(n / 16);
    if (n % 16 < 10)
        _putchar((n % 16) + '0');
    else
        _putchar((n % 16) - 10 + 'a');
}

/**
 * main - prints the opcodes of its own main function
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 on success, 1 or 2 on error
 */
int main(int argc, char *argv[])
{
    int i, n;
    unsigned char *p;

    if (argc != 2)
    {
        _putchar('E');
        _putchar('r');
        _putchar('r');
        _putchar('o');
        _putchar('r');
        _putchar('\n');
        exit(1);
    }
    n = atoi(argv[1]);
    if (n < 0)
    {
        _putchar('E');
        _putchar('r');
        _putchar('r');
        _putchar('o');
        _putchar('r');
        _putchar('\n');
        exit(2);
    }
    p = (unsigned char *)main;
    for (i = 0; i < n; i++)
    {
        print_hex(p[i]);
        if (i < n - 1)
            _putchar(' ');
    }
    _putchar('\n');
    return (0);
}
