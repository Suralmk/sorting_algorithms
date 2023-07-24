#include "sort.h"

/**
 * change_int - this func swap two numbers
 * @firstnum: first number
 * @secondnum: second number
 */
void change_int(int *firstnum, int *secondnum)
{
	int temp;

	temp = *firstnum;
	*firstnum = *secondnum;
	*secondnum = temp;
}

/**
 * selection_sort - Sort an array of integers in ascending order
 *                  using the selection sort algorithm.
 * @array: An array
 * @size: size of the array.
 */
void selection_sort(int *array, size_t size)
{
	int *minimum;
	size_t x, y;

	if (!array || size < 2)
		return;

	for (x = 0; x < size - 1; x++)
	{
		minimum = array + x;
		y = x + 1;
		while (y < size)
		{
			minimum = (array[y] < *minimum) ? (array + y) : minimum;
			y++;
		}

		if ((array + x) != minimum)
		{
			change_int(array + x, minimum);
			print_array(array, size);
		}
	}
}
