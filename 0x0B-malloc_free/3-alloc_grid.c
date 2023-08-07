#include "main.h"

/**
 * alloc_grid - returns a pointer to a 2 dimensional array of integers
 * @width: width of the grid
 * @height: height of the grid
 *
 * Return: pointer to the grid, or NULL if it fails
 */
int **alloc_grid(int width, int height)
{
	int **grid; /* pointer to an array, hence the two asteriks */
	int i, j;

	if (width <= 0 || height <= 0) /* check if width or height are invalid */
		return (NULL);

	/* allocate memory for grid */
	grid = malloc(height * sizeof(int *));
	if (grid == NULL) /* check if allocation failed */
		return (NULL);

	/* allocate memory for each row */
	for (i = 0; i < height; i++)
	{
		grid[i] = malloc(width * sizeof(int));
		if (grid[i] == NULL) /* check if allocation failed */
		{
			/* free previously allocated memory */
			for (j = 0; j < i; j++)
				free(grid[j]);
			free(grid);
			return (NULL);
		}
	}

	/* initialize all elements to 0 */
	for (i = 0; i < height; i++)
		for (j = 0; j < width; j++)
			grid[i][j] = 0;

	return (grid);
}

