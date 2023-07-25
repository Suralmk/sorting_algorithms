#include "sort.h"

void merge_second(int *second, int *lock, size_t first, size_t center,
		size_t last);
void merge_sort_recursive(int *second, int *lock, size_t first, size_t last);
void merge_sort(int *array, size_t size);



/**
 * merge_sort - Sort an array of integers in ascending
 *              order using the merge sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
	int *lock;

	if (!array || size < 2)
		return;

	lock = malloc(sizeof(int) * size);
	if (!lock)
		return;

	merge_sort_recursive(array, lock, 0, size);

	free(lock);
}
/**
 * merge_second - Sort a seconday of integers.
 * @second: A second array
 * @lock: A buffer
 * @first: The first index
 * @center: The centerex in the centerdle(cenetr)
 * @last: The last index
 */
void merge_second(int *second, int *lock, size_t first, size_t center,
		size_t last)
{
	size_t x, y, z = 0;

	printf("Merging...\n[left]: ");
	print_array(second + first, center - first);

	printf("[right]: ");
	print_array(second + center, last - center);

	x = first;
	y = center;
	while (x < center && y < last)
	{
		lock[z] = (second[x] < second[y]) ? second[x++] : second[y++];
		z++;
	}

	while (x < center)
	{
		lock[z++] = second[x];
		x++;
	}

	while (y < last)
	{
		lock[z++] = second[y];
		y++;
	}

	x = first;
	z = 0;
	while (x < last)
	{
		second[x] = lock[z++];
		x++;
	}

	printf("[Done]: ");
	print_array(second + first, last - first);
}

/**
 * merge_sort_recursive - Implement the merge sort algorithm through recursion.
 * @second: A seconday of an array of integers to sort.
 * @lock: A buffer to store the sorted result.
 * @first: The first index of the seconday.
 * @last: The last index of the seconday.
 */
void merge_sort_recursive(int *second, int *lock, size_t first, size_t last)
{
	size_t center;

	if (last - first > 1)
	{
		center = first + (last - first) / 2;
		merge_sort_recursive(second, lock, first, center);
		merge_sort_recursive(second, lock, center, last);
		merge_second(second, lock, first, center, last);
	}
}