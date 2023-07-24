#include "sort.h"

/**
 * swap_ints - this func swap two numbers
 * @firstnum: first number
 * @secondnum: second number
 */
void swap_ints(int *firstnum, int *secondnum)
{
	int temp;

	temp = *firstnum;
	*firstnum = *secondnum;
	*secondnum = temp;
}