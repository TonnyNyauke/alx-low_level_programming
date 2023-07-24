#include "main.h"

/**
 * _atoi - convert a string to an integer
 * @s: pointer to the string
 * Return: the integer value of the string
 */
int _atoi(char *s)
{
	int i; /* variable to loop over the string */
	int sign; /* variable to store the sign of the number */
	int num; /* variable to store the number */

	i = 0;
	sign = 1;
	num = 0;

	/* skip any non-digit characters */
	while (s[i] < '0' || s[i] > '9')
	{
		/* change the sign if there is a - or + sign */
		if (s[i] == '-')
		{
			sign *= -1;
		}
		else if (s[i] == '+')
		{
			sign *= 1;
		}
		/* move to the next character */
		i++;
	}

	/* convert the digits to an integer */
	while (s[i] >= '0' && s[i] <= '9')
	{
		/* multiply the previous number by 10 and add the current digit */
		num = num * 10 + (s[i] - '0');
		/* move to the next character */
		i++;
	}

	/* return the number with the sign */
	return (num * sign);
}
