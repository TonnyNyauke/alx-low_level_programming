#include "main.h"
#include <stdio.h>

/**
 * print_times_table - prints the n times table, starting with 0
 * @n: the number of the times table to print
 */
void print_times_table(int n)
{
	int i, j, p;

	if (n >= 0 && n <= 15)
	{
		for (i = 0; i <= n; i++)
		{
			for (j = 0; j <= n; j++)
			{
				p = i * j;
				if (j != 0)
				{
					printf(", ");
				}
				if (p < 10)
				{
					printf("  %d", p);
				}
				else if (p < 100)
				{
					printf(" %d", p);
				}
				else
				{
					printf("%d", p);
				}
			}
			printf("\n");
		}
	}
}

