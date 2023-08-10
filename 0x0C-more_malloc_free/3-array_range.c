#include "main.h"

/**
 * array_range - creates an array of integers
 * @min: minimum value (included)
 * @max: maximum value (included)
 *
 * Return: pointer to the newly created array, or NULL if failure
 */
int *array_range(int min, int max)
{
	int *arr;
	int i, size;

	/* if min > max, return NULL */
	if (min > max)
		return (NULL);

	/* calculate the size of the array */
	size = max - min + 1;

	/* allocate memory for the array */
	arr = malloc(sizeof(int) * size);
	if (arr == NULL)
		return (NULL);

	/* initialize the array with values from min to max */
	for (i = 0; i < size; i++)
		arr[i] = min + i;

	return (arr);
}

