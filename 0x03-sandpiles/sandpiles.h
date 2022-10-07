#ifndef SANDPILES_H
#define SANDPILES_H

#include <stdio.h>
#include <stdlib.h>

static void print_grid(int grid[3][3]);
void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
int not_stable(int grid[3][3], int stability_grid[3][3]);
void topple(int grid[3][3], int row, int column);

#endif
