#include "sort.h"

/**
 * bubble_sort - sort an array of integers
 * @array: an array to be sorted
 * @size: size of array
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
