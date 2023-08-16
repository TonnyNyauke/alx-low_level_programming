#include "function_pointers.h"

/**
 * print_name - Prints a name using a specified format function.
 * @name: The name to be printed.
 * @f: A function pointer to the printing format function.
 *
 * Return: Nothing.
 */
void print_name(char *name, void (*f)(char *))
{
	f(name);
}

