#include "menger.h"
#include <math.h>

/**
 * menger - Draws a 2D Menger Sponge
 * @level: Level of the Menger Sponge being drawn
 */
void menger(int level)
{
	int size, row, col, i, j;
	char print;

	if (level < 0)
		return;

	size = pow(3, level);
	for (row = 0; row < size; row++)
	{
		for (col = 0; col < size; col++)
		{
			i = row;
			j = col;
			print = '#';
			while (i > 0 || j > 0)
			{
				if (i % 3 == 1 && j % 3 == 1)
					print = ' ';
				i /= 3;
				j /= 3;
			}
			printf("%c", print);
		}
		printf("\n");
	}
}
