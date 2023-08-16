#include "function_pointers.h"

/**
 * int_index - searches for an integer in an array using a comparison function
 * @array: the array to search in
 * @size: the size of the array
 * @cmp: the comparison function to use
 *
 * Return: the index of the first element that matches the comparison,
 * or -1 if none or size <= 0
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array == NULL || cmp == NULL)
		return (-1);

	if (size <= 0)
		return (-1);

	for (i = 0; i < size; i++)
	{
		if (cmp(array[i]))
			return (i)
	}

	return (-1);
}
