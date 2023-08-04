#include "main.h"

/**
 * main - prints the minimum number of coins to make change
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 if successful, 1 if not
 */
int main(int argc, char *argv[])
{
	int cents, coins, quarters, dimes, nickels, twos, ones;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	cents = atoi(argv[1]);
	coins = 0;

	if (cents > 0)
	{
		quarters = cents / 25;
		dimes = (cents % 25) / 10;
		nickels = ((cents % 25) % 10) / 5;
		twos = (((cents % 25) % 10) % 5) / 2;
		ones = (((cents % 25) % 10) % 5) % 2;
		coins = quarters + dimes + nickels + twos + ones;
	}

	printf("%d\n", coins);

	return (0);
}

