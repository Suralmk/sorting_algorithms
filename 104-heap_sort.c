#include "sort.h"

void change_int(int *a, int *b);
void heap_max(int *array, size_t size, size_t index, size_t local);
void heap_sort(int *array, size_t size);

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
 * heap_max - change tree to heap
 * @array: An array of integers
 * @size: The size of the array/tree.
 * @index: The index of the index
 * @local: The local node of the binary tree.
 */
void heap_max(int *array, size_t size, size_t index, size_t local)
{
	size_t before, after, big_one;

	before = 2 * local + 1;
	after = 2 * local + 2;
	big_one = local;

	if (before < index && array[before] > array[big_one])
		big_one = before;
	if (after < index && array[after] > array[big_one])
		big_one = after;

	if (big_one != local)
	{
		change_int(array + local, array + big_one);
		print_array(array, size);
		heap_max(array, size, index, big_one);
	}
}

/**
 * heap_sort - Sort an array of integers in ascending
 *             order using the heap sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	i = (size / 2) - 1;
	while (i >= 0)
	{
		heap_max(array, size, size, i);
		i--;
	}

	i = size - 1;
	while (i > 0)
	{
		change_int(array, array + i);
		print_array(array, size);
		heap_max(array, size, i, 0);
		i--;
	}
}
