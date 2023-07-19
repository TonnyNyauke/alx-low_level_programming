#include <stdio.h>
#include "main.h"

/**
 * print_to_98 - prints all natural numbers from n to 98
 * @n: the starting point
 * Return: nothing
 */
void print_to_98(int n)
{
	if (n <= 98)
	{
		for (; n < 98; n++)
		{
			printf("%d, ", n);
		}
		printf("98\n");
	}
	else
	{
		for (; n > 98; n--)
		{
			printf("%d, ", n);
		}
		printf("98\n");
	}
}
