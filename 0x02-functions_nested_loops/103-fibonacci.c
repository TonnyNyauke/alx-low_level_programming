#include <stdio.h>

/**
 * main - finds and prints the sum of the even-valued terms in the Fibonacci
 * sequence whose values do not exceed 4,000,000
 * Return: Always 0 (Success)
 */
int main(void)
{
	long int t1 = 1, t2 = 2, next = 0, sum = 2;

	while (next <= 4000000)
	{
		next = t1 + t2;
		if (next % 2 == 0)
		{
			sum += next;
		}
		t1 = t2;
		t2 = next;
	}
	printf("%ld\n", sum);
	return (0);
}

