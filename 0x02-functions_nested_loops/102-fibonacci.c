#include <stdio.h>

/**
 * main - prints the first 50 Fibonacci numbers, starting with 1 and 2
 * Return: Always 0 (Success)
 */
int main(void)
{
	long int i, t1 = 1, t2 = 2, next;

	printf("%ld, %ld", t1, t2);
	for (i = 3; i <= 50; i++)
	{
		next = t1 + t2;
		printf(", %ld", next);
		t1 = t2;
		t2 = next;
	}
	printf("\n");

	return (0);
}

