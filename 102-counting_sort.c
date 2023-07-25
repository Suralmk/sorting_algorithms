#include "sort.h"

int find_big_num(int *array, int size);

/**
 * counting_sort - Sort an array of integers in ascending order
 *                 using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void counting_sort(int *array, size_t size)
{
	int *place_c, *sorted_array, big, i;

	if (!array || size < 2)
		return;

	sorted_array = malloc(sizeof(int) * size);
	if (sorted_array == NULL)
		return;
	big = get_max(array, size);
	place_c = malloc(sizeof(int) * (big + 1));
	if (place_c == NULL)
	{
		free(sorted_array);
		return;
	}

	i = 0;
	while (i < (big + 1))
	{
		place_c[i] = 0;
		i++;
	}

	i = 0;
	while (i < (int)size)
	{
		place_c[array[i]] += 1;
		i++;
	}

	i = 0;
	while (i < (big + 1))
	{
		place_c[i] += place_c[i - 1];
		i++;
	}

	print_array(place_c, big + 1);

	i = 0;
	while (i < (int)size)
	{
		sorted_array[place_c[array[i]] - 1] = array[i];
		place_c[array[i]] -= 1;
		i++;
	}

	i = 0;
	while (i < (int)size)
	{
		array[i] = sorted_array[i];
		i++;
	}

	free(sorted_array);
	free(place_c);
}

/**
 * find_big_num - return the big value
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