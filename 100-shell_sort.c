#include "sort.h"


void swap_ints(int *firstnum, int *secondnum);


/**
 * shell_sort - Sort an array of integers in ascending
 *              order using the shell sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
	size_t space, x, y;

	if (!array || size < 2)
		return;

	space = 1;
	while (space < (size / 3))
		space = space * 3 + 1;

	for (; space >= 1; space /= 3)
	{
		for (x = space; x < size; x++)
		{
			for (y = x; y >= space && array[y - space] > array[y]; y -= space)
			{
				swap_ints(array + y, array + (y - space));
			}
		}
		print_array(array, size);

	}
}

/**
 * swap_ints - this func swap two numbers
 * @firstnum: first number
 * @secondnum: second number
 */
 void swap_ints(int *firstnum, int *secondnum)
{
	int temp;

	temp = *firstnum;
	*firstnum = *secondnum;
	*secondnum = temp;
}