#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - generates random valid passwords for the program 101-crackme
 *
 * Return: Always 0.
 */
int main(void)
{
	int sum;
	char c;

	srand(time(0));

	for (sum = 0; sum < 2772; sum += c)
	{
		c = rand() % 128;
		if ((sum + c) > 2772)
			break;
		printf("%c", c);
	}
	printf("%c", 2772 - sum);

	return (0);
}

