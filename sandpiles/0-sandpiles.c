#include <stdio.h>
#include "sandpiles.h"

/**
 * print_sandpile - Prints a 3x3 grid
 * @grid: 3x3 grid to print
 */
void print_sandpile(int grid[3][3])
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


/**
 * is_stable - Checks if a sandpile is stable
 * @grid: 3x3 grid to check
 *
 * Return: 1 if stable, 0 otherwise
 *
 */

int is_stable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (grid[i][j] > 3)
				return (0);

	return (1);
}


/**
 * topple_round - Topples every unstable cell of a sandpile once
 * @grid: 3x3 grid to topple
 */

void topple_round(int grid[3][3])
{
	int i, j;
	int copy[3][3];

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			copy[i][j] = grid[i][j];

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (copy[i][j] > 3)
			{
				grid[i][j] -= 4;
				if (i > 0)
					grid[i - 1][j] += 1;
				if (i < 2)
					grid[i + 1][j] += 1;
				if (j > 0)
					grid[i][j - 1] += 1;
				if (j < 2)
					grid[i][j + 1] += 1;
			}
		}
	}
}

/**
 * sandpiles_sum - Computes the sum of two sandpiles
 * @grid1: First 3x3 grid, receives the stable result
 * @grid2: Second 3x3 grid
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid1[i][j] += grid2[i][j];

	while (!is_stable(grid1))
	{
		printf("=\n");
		print_sandpile(grid1);
		topple_round(grid1);
	}
}
