#include "sort.h"

void change_int(int *a, int *b);
void merge_bio(int *array, size_t size, size_t begin, size_t sequence,
		char direction);
void sequence_bio(int *array, size_t size, size_t begin, size_t sequence, char direction);
void bitonic_sort(int *array, size_t size);

/**
 * bitonic_sort - Sort an array of integers in ascending
 *                order using the bitonic sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	sequence_bio(array, size, 0, size, UP);
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
 * merge_bio - Sort a bitonic sequenceuence inside an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 * @begin: The begining index.
 * @sequence: The size of the sequence to sort.
 * @direction: The direction to sort in.
 */
void merge_bio(int *array, size_t size, size_t begin, size_t sequence,
		char direction)
{
	size_t i, wide = sequence / 2;

	if (sequence > 1)
	{
		i = begin; 
		while (i < begin + wide)
		{
			if ((direction == UP && array[i] > array[i + wide]) ||
			    (direction == DOWN && array[i] < array[i + wide]))
				change_int(array + i, array + i + wide);
			i++;
		}
		merge_bio(array, size, begin, wide, direction);
		merge_bio(array, size, begin + wide, wide, direction);
	}
}

/**
 * sequence_bio - Convert an array of integers into a bitonic sequenceuence.
 * @array: An array of integers.
 * @size: The size of the array.
 * @begin: The begining index of a block of the building bitonic sequenceuence.
 * @sequence: The size of a block of the building bitonic sequenceuence.
 * @direction: The direction to sort the bitonic sequenceuence block in.
 */
void sequence_bio(int *array, size_t size, size_t begin, size_t sequence, char direction)
{
	size_t drop = sequence / 2;
	char *str = (direction == UP) ? "UP" : "DOWN";

	if (sequence > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", sequence, size, str);
		print_array(array + begin, sequence);

		sequence_bio(array, size, begin, drop, UP);
		sequence_bio(array, size, begin + drop, drop, DOWN);
		merge_bio(array, size, begin, sequence, direction);

		printf("Result [%lu/%lu] (%s):\n", sequence, size, str);
		print_array(array + begin, sequence);
	}
}