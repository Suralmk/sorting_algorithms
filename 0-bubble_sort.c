#include "sort.h"

/**
 * change_swap - this function swap the position of two integers in an array
 * @num1: the first number
 * @num2: the second number
 */
void change_swap(int *num1, int *num2)
{
	int temp;

	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

/**
 * bubble_sort -This function sorts array of integers in ascending order.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap of numbers.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i = 0, length = size;
	bool is_bubble = false;

	if (array == NULL || size < 2)
		return;

	while (is_bubble == false)
	{
		is_bubble = true;
		while (i < length - 1)
		{
			if (array[i] > array[i + 1])
			{
				change_swap(array + i, array + i + 1);
				print_array(array, size);
				is_bubble = false;
			}
			i++;
		}
		length--;
	}
}
		