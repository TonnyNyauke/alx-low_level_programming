#include "main.h"
#include <stdio.h>

/**
 * infinite_add - adds two numbers
 * @n1: first number
 * @n2: second number
 * @r: buffer to store result
 * @size_r: buffer size
 * Return: pointer to result or 0 if it does not fit in r
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int i, j, k, l, m, n;
	int carry, digit, sum;

	i = 0;
	while (n1[i] != '\0')
		i++;
	j = 0;
	while (n2[j] != '\0')
		j++;
	if (i > size_r || j > size_r)
		return (0);
	k = 0;
	carry = 0;
	i--;
	j--;
	while (i >= 0 || j >= 0 || carry > 0)
	{
		if (i >= 0)
			m = n1[i] - '0';
		else
			m = 0;
		if (j >= 0)
			n = n2[j] - '0';
		else
			n = 0;
		sum = m + n + carry;
		if (sum > 9)
		{
			digit = sum % 10;
			carry = sum / 10;
		}
		else
		{
			digit = sum;
			carry = 0;
		}
		r[k] = digit + '0';
		k++;
		i--;
		j--;
		if (k >= size_r)
			return (0);
	}
	r[k] = '\0';

	l = k - 1;
	for (k = 0; k < l; k++, l--)
	{
		char tmp = r[k];
		r[k] = r[l];
		r[l] = tmp;
	}
	return (r);
}
