#include "main.h"

/**
 * set_string - sets the value of a pointer to a char
 * @s: pointer to a pointer to a char
 * @to: pointer to a char
 *
 * Return: void
 */
void set_string(char **s, char *to)
{
	*s = to; /* assign the value of to to the pointer pointed by s */
}

