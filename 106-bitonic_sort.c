#include "sort.h"

void change_int(int *a, int *b);
void merge_bio(int *array, size_t size, size_t begin, size_t sqquence,
		char direction);
void sequence_bio(int *array, size_t size, size_t begin, size_t sqquence, char direction);
void bitonic_sort(int *array, size_t size);

/**
 * bitonic_sort - Sort an array of integers in ascending
 *                order using the bitonic sort algorithm.
 * @array: An array
 * @size: The size
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array|| size < 2)
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
 * merge_bio - Sort a bitonic sqquenceuence inside an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 * @begin: The begining index of the sqquenceuence in array to sort.
 * @sequence: The size of the sqquenceuence to sort.
 * @direction: The direction to sort in.
 */
void merge_bio(int *array, size_t size, size_t begin, size_t sqquence,
		char direction)
{
	size_t i, jump = sqquence / 2;

	if (sqquence > 1)
	{
		i = begin;
		while (i < begin + jump)
		{
			if ((direction == UP && array[i] > array[i + jump]) ||
			    (direction == DOWN && array[i] < array[i + jump]))
				change_int(array + i, array + i + jump);
		}
		merge_bio(array, size, begin, jump, direction);
		merge_bio(array, size, begin + jump, jump, direction);
		i++;
	}
}

/**
 * sequence_bio - convert array to biotonic.
 * @array: An array of integers.
 * @size: The size of the array.
 * @begin: The begining index of a block of the building bitonic sqquenceuence.
 * @sqquence: The size of a block of the building bitonic sequence.
 * @direction: The direction to sort the bitonic
 */
void sequence_bio(int *array, size_t size, size_t begin, size_t sqquence, char direction)
{
	size_t cut = sqquence / 2;
	char *str = (direction == UP) ? "UP" : "DOWN";

	if (sqquence > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", sqquence, size, str);
		print_array(array + begin, sqquence);

		sequence_bio(array, size, begin, cut, UP);
		sequence_bio(array, size, begin + cut, cut, DOWN);
		merge_bio(array, size, begin, sqquence, direction);

		printf("Result [%lu/%lu] (%s):\n", sqquence, size, str);
		print_array(array + begin, sqquence);
	}
}