#!/usr/bin/python3
"""
0-island_perimeter
"""


def island_perimeter(grid):
    """
    Calculates the perimeter of an island in a grid of 0s and 1s.
    Args:
    - grid: a list of lists of integers representing the grid.
      - 0 represents water
      - 1 represents land
      - The grid is rectangular, with its width and height not exceeding 100
      - The grid is completely surrounded by water
      - There is only one island (or nothing).
      - The island doesn’t have “lakes” (water inside that isn’t connected
            to the water surrounding the island).
    Returns:
    - The perimeter of the island in the grid.
    Example:
    >>> grid = [
    ...     [0, 0, 0, 0, 0, 0],
    ...     [0, 1, 0, 0, 0, 0],
    ...     [0, 1, 0, 0, 0, 0],
    ...     [0, 1, 1, 1, 0, 0],
    ...     [0, 0, 0, 0, 0, 0]
    ... ]
    >>> island_perimeter(grid)
    12
    """
    perimeter = 0
    for i in range(len(grid)):
        for j in range(len(grid[i])):
            if grid[i][j] == 1:
                perimeter += check_neighbors(grid, i, j)
    return perimeter


def check_neighbors(array, col, row):
    """
    Calculates the number of land neighbors for a cell in a grid.
    Args:
    - array: a list of lists of integers representing the grid.
      - 0 represents water
      - 1 represents land
    - col: the index of the column of the cell to check.
    - row: the index of the row of the cell to check.
    Returns:
    - The number of land neighbors for the cell at the
        specified row and column.
    Example:
    >>> grid = [
    ...     [0, 0, 0],
    ...     [0, 1, 0],
    ...     [0, 0, 0]
    ... ]
    >>> check_neighbors(grid, 1, 1)
    1
    """
    perimeter = 4
    if array[col][row] == 1:
        if row + 1 < len(array[col]) and array[col][row + 1] == 1:
            perimeter -= 1
        if row - 1 >= 0 and array[col][row - 1] == 1:
            perimeter -= 1
        if col + 1 < len(array) and array[col + 1][row] == 1:
            perimeter -= 1
        if col - 1 >= 0 and array[col - 1][row] == 1:
            perimeter -= 1
    return perimeter
