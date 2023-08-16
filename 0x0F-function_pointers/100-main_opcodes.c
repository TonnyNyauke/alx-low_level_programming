#include "function_pointers.h"

/**
 * main - entry point
 * @argc: Number of arguments passed to program
 * @argv: Array of strings containing the arguments passed to program
 * Return: Always 0
 */

int main(int argc, char **argv)
{
	int i, bytes;
	char *arr;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}

	bytes = atoi(argv[1]);

	if (bytes < 0)
	{
		printf("Error\n");
		exit(2);
	}

	arr = (char *)main;

	for (i = 0; i < bytes; i++)
	{
		if (i == bytes - 1)
		{
			printf("%02hhx\n", arr[i]);
			break;
		}
		printf("%02hhx ", arr[i]);
	}
	return (0);
}
