#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - Print array elemnts
 *
 * @array: Printed array
 * @size: size of the array
 */
void print_array(const int *array, size_t size)
{
	size_t n;

	for (n = 0; array && n < size; ++n)
	{
		if (n > 0)
			printf(", ");
		printf("%d", array[n]);
	}
	printf("\n");
}	