#include "main.h"

/**
 * _sqrt - helper function to find the square root of n
 * @n: number to find the square root of
 * @i: possible square root
 * Return: square root of n or -1 if n has no natural square root
 */
int _sqrt(int n, int i)
{
	if (i * i == n)
	{
		return (i);
	}
	if (i * i > n)
	{
		return (-1);
	}
	return (_sqrt(n, i + 1));
}

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: number to find the square root of
 * Return: square root of n or -1 if n has no natural square root
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
	{
		return (-1);
	}
	return (_sqrt(n, 0));
}

