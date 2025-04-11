#include "sort.h"
#include <stdio.h>

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	if (a == NULL || b == NULL)
		return;

	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - Sorts an array of integers in ascending order
 *                 using the selection sort algorithm.
 * @array: The array of integers to sort.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap operation.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int *min;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = array + i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < *min)
				min = array + j;
		}

		if (min != array + i)
		{
			swap_ints(array + i, min);
			print_array(array, size);
		}
	}
}
