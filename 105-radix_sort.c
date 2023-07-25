#include "sort.h"

int find_big_num(int *array, int size);
void sort_radix_counting(int *array, size_t size, int s, int *lock);
void radix_sort(int *array, size_t size);

/**
 * radix_sort - Sort an array of integers in ascending
 *              order using the radix sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void radix_sort(int *array, size_t size)
{
	int big, s, *lock;

	if (array == NULL || size < 2)
		return;

	lock = malloc(sizeof(int) * size);
	if (lock == NULL)
		return;

	big = find_big_num(array, size);
	s = 1;
	while (big / s > 0)
	{
		sort_radix_counting(array, size, s, lock);
		print_array(array, size);
		s *= 10;
	}

	free(lock);
}
/**
 * find_big_num - return the max value
 * @array: An array
 * @size: The size
 *
 * Return: maximum number from the array
 */
int find_big_num(int *array, int size)
{
	int big, i;

	big = array[0];
	i = 1;
	while ( i < size)
	{
		if (array[i] > big)
			big = array[i];
		i++;
	}

	return (big);
}

/**
 * sort_radix_counting - Sort the snificant digits of an array of integers
 *                       in ascending order using the counting sort algorithm.
 * @array: An array
 * @size: The size
 * @s: number sorting is applied
 * @lock: buffer to store numbers
 */
void sort_radix_counting(int *array, size_t size, int s, int *lock)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i = 0;

	while (i < size)
		count[(array[i] / s) % 10] += 1;
		i++;

	i = 0;
	while (i < 10)
		count[i] += count[i - 1];
		i++;

	i = size - 1;
	while ((int)i >= 0)
	{
		lock[count[(array[i] / s) % 10] - 1] = array[i];
		count[(array[i] / s) % 10] -= 1;
		i--;
	}

	i = 0;
	while (i < size)
		array[i] = lock[i];
		i++;
}