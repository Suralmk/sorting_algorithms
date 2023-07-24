#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @firstnum: The first integer to swap.
 * @secondnum: The second integer to swap.
 */
void swap_ints(int *firstnum, int *secondnum)
{
	int temp;

	temp = *firstnum;
	*firstnum = *secondnum;
	*secondnum = temp;
}

/**
 * bubble_sort - Sort an array of integers in ascending order.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, length = size;
	bool isbubbly = false;

	if (array == NULL || size < 2)
		return;

	while (isbubbly == false)
	{
		isbubbly = true;
		for (i = 0; i < length - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_ints(array + i, array + i + 1);
				print_array(array, size);
				isbubbly = false;
			}
		}
		length--;
	}
}
