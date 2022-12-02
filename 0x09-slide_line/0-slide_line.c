#include "slide_line.h"

/**
* slide_line - slides and merges an array of integers
* @line: pointer to array
* @size: size of array
* @direction: direction to merge
* Return: 1 on success, 0 on failure
*/
int slide_line(int *line, size_t size, int direction)
{
	if (!line || size < 1)
		return (0);
	if (direction == SLIDE_LEFT || direction == SLIDE_RIGHT)
		return (slide_it(line, size, direction));
	return (0);
}

/**
* slide_it - slides and merges an array of integers to the
* left if intergers match
* @line: pointer to array
* @size: size of array
* @direction: direction to merge
* Return: 1 on success, 0 on failure
*/
int slide_it(int *line, size_t size, int direction)
{
	size_t i, j;

	if (direction == SLIDE_RIGHT)
		reverse_array(line, size);

	for (i = 0; i < size; i++)
	{
		if (line[i] == 0)
		{
			for (j = i; j < size; j++)
			{
				if (line[j] != 0)
				{
					line[i] = line[j];
					line[j] = 0;
					break;
				}
			}
		}
	}
	add_array(line, size);
	/* slide greater than 0 ints to left most index */
	for (i = 0; i < size; i++)
	{
		if (line[i] == 0)
		{
			for (j = i; j < size; j++)
			{
				if (line[j] != 0)
				{
					line[i] = line[j];
					line[j] = 0;
					break;
				}
			}
		}
	}
	if (direction == SLIDE_RIGHT)
		reverse_array(line, size);
	return (1);
}

/**
* reverse_array - reverses an array
* @line: array
* @size: size of the array
*/
void reverse_array(int *line, size_t size)
{
	int i, j, temp;

	for (i = 0, j = size - 1; i < j; i++, j--)
	{
		temp = line[i];
		line[i] = line[j];
		line[j] = temp;
	}
}

/**
* add_array - adds the left side of the array
* @line: array
* @size: size of the array
*/
void add_array(int *line, size_t size)
{
	size_t k;

	for (k = 0; k < size - 1; k++)
	{
		if (line[k] == line[k + 1])
		{
			line[k] = line[k] + line[k + 1];
			line[k + 1] = 0;
		}
	}
}
