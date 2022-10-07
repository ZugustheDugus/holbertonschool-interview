#include "sandpiles.h"

/**
 * sandpiles_sum - Stably computes the sum of two sandpile grids.
 *
 * @grid1: First sandpile grid
 * @grid2: Second sandpile grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int row, column;
	int stablity_grid[3][3] = {{0}};

	for (row = 0; row < 3; row++)
	{
		for (column = 0; column < 3; column++)
			grid1[row][column] += grid2[row][column];
	}
	while (not_stable(grid1, stablity_grid))
	{
		printf("=\n");
		print_grid(grid1);
		for (row = 0; row < 3; row++)
		{
			for (column = 0; column < 3; column++)
			{
				if (stablity_grid[row][column] == 1)
					topple(grid1, row, column);
			}
		}
	}
}

/**
 * not_stable - Determines if sandpile grid is stable.
 *
 * @grid: Sandpile grid to be altered.
 * @stability_grid: Grid to show which cells need toppling.
 *
 * Return: 0 if stable, 1 if not
 */
int not_stable(int grid[3][3], int stability_grid[3][3])
{
	int is_stable = 0;
	int row, column;

	for (row = 0; row < 3; row++)
	{
		for (column = 0; column < 3; column++)
		{
			if (grid[row][column] > 3)
			{
				is_stable = 1;
				stability_grid[row][column] = 1;
			}
			else
			{
				stability_grid[row][column] = 0;
			}
		}
	}
	return (is_stable);
}

/**
 * topple - Topples the current sandpile.
 *
 * @grid: Sandpile grid to be altered.
 * @row: The row coordinate.
 * @column: The column coordinate.
 */
void topple(int grid[3][3], int row, int column)
{
	grid[row][column] -= 4;
	if (row - 1 >= 0)
		grid[row - 1][column] += 1;
	if (row + 1 < 3)
		grid[row + 1][column] += 1;
	if (column - 1 >= 0)
		grid[row][column - 1] += 1;
	if (column + 1 < 3)
		grid[row][column + 1] += 1;
}

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}
