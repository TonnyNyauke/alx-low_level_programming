#include <stdio.h>

/**
 * main - finds and prints the first 98 Fibonacci numbers,
 * starting with 1 and 2
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i;
	unsigned long int t1 = 0, t2 = 1, n = 0;

	printf("%lu, %lu", t1, t2);
	for (i = 3; i <= 98; i++)
	{
		n = t1 + t2;
		printf(", %lu", n);
		t1 = t2;
		t2 = n;
	}
	printf("\n");
	return (0);
}
