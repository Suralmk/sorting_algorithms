#include "sort.h"

void change_int(int *firstnum, int *secondnum);
int find_partision(int *array, size_t size, int left, int right);
void partition_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);


/**
 * quick_sort - Sort an array of integers in ascending
 *              order using the quicksort algorithm.
 * @array: An array
 * @size: Array Size
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	partition_sort(array, size, 0, size - 1);
}

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
 * find_partision - Order a subset of an array of integers according to
 *                    the lomuto partition scheme (last element as end).
 * @array: The array
 * @size: size of the array.
 * @left: The starting index
 * @right: The ending index
 *
 * Return: index for partision
 */
int find_partision(int *array, size_t size, int left, int right)
{
	int *end, up, down;

	end = array + right;
	up = down = left;
	while (down < right)
	{
		if (array[down] < *end)
		{
			if (up < down)
			{
				change_int(array + down, array + up);
				print_array(array, size);
			}
			up++;
		}
		down++;
	}

	if (array[up] > *end)
	{
		change_int(array + up, end);
		print_array(array, size);
	}

	return (up);
}

/**
 * partition_sort - Implement the quicksort algorithm through recursion.
 * @array: An array
 * @size: Array size
 * @left: The starting index
 * @right: The ending index
 */
void partition_sort(int *array, size_t size, int left, int right)
{
	int partition;

	if (right - left > 0)
	{
		partition = find_partision(array, size, left, right);
		partition_sort(array, size, left, partition - 1);
		partition_sort(array, size, partition + 1, right);
	}
}
