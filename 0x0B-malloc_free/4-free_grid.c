#include "main.h"
#include <stdlib.h>

/**
 * free_grid - Frees a 2-dimensional grid created by alloc_grid.
 * @grid: Pointer to the 2D grid.
 * @height: Height of the grid.
 *
 * This function frees the memory allocated for a 2-dimensional grid.
 */
void free_grid(int **grid, int height)
{
	int i; /* Move the declaration to the beginning of the function */

	if (grid == NULL || height <= 0)
		return;

	for (i = 0; i < height; i++)
	{
		free(grid[i]);
	}

	free(grid);
}
