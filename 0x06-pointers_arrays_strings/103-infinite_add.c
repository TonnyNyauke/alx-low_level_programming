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
	while (n1[i] != '\0')/* get the length of n1 */
		i++;
	j = 0;
	while (n2[j] != '\0')/* get the length of n2 */
		j++;
	if (i > size_r || j > size_r)/* check if result will fit in r */
		return (0);
	k = 0;
	carry = 0;
	i--;/* start from the last digit of n1 */
	j--;/* start from the last digit of n2 */
	while (i >= 0 || j >= 0 || carry > 0)
	{
		if (i >= 0)/* get the digit of n1 at position i */
			m = n1[i] - '0';
		else
			m = 0;
		if (j >= 0)/* get the digit of n2 at position j */
			n = n2[j] - '0';
		else
			n = 0;
		sum = m + n + carry;/* add the digits and the carry */
		if (sum > 9)/* if sum is more than one digit */
		{
			digit = sum % 10;/* get the last digit of sum */
			carry = sum / 10;/* get the carry */
		}
		else
		{
			digit = sum;/* get the digit of sum */
			carry = 0;/* no carry */
		}
		r[k] = digit + '0';/* store the digit in r at position k */
		k++;
		i--;
		j--;
		if (k >= size_r)/* check if r is full */
			return (0);
	}
	r[k] = '\0';/* terminate r with null byte */

	l = k - 1;/* get the index of the last digit in r */
	for (k = 0; k < l; k++, l--)/* reverse r to get the correct order */
	{
		char tmp = r[k];
		r[k] = r[l];
		r[l] = tmp;
	}
	return (r);/* return pointer to r */
}

