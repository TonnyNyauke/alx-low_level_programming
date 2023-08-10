#include "main.h"

/**
 * _realloc - reallocates a memory block using malloc and free
 * @ptr: pointer to the memory previously allocated with malloc
 * @old_size: size, in bytes, of the allocated space for ptr
 * @new_size: new size, in bytes, of the new memory block
 *
 * Return: pointer to the new memory block, or NULL if failure
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new_ptr;
	unsigned int i, min_size;

	/* if new_size == old_size, do not do anything and return ptr */
	if (new_size == old_size)
		return (ptr);

	/* if ptr is NULL, call is equivalent to malloc(new_size) */
	if (ptr == NULL)
		return (malloc(new_size));

	/* if new_size is 0 and ptr is not NULL, call is equivalent to free(ptr) */
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	/* allocate memory for the new block */
	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);

	/* get the minimum of the old and new sizes */
	min_size = old_size < new_size ? old_size : new_size;

	/* copy the contents from the old block to the new block */
	for (i = 0; i < min_size; i++)
		new_ptr[i] = ((char *)ptr)[i];

	/* free the old block */
	free(ptr);

	return (new_ptr);
}

