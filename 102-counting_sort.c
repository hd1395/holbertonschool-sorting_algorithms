#include "sort.h"
#include <stdlib.h>

/**
 * counting_sort - Sorts an array of integers using the Counting sort algorithm
 * @array: Array of integers to sort
 * @size: Size of the array
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sorted;
	int max, i;
	size_t j;

	if (!array || size < 2)
		return;

	/* Find maximum value in array */
	max = array[0];
	for (j = 1; j < size; j++)
	{
		if (array[j] > max)
			max = array[j];
	}

	/* Allocate memory for count and sorted arrays */
	count = malloc(sizeof(int) * (max + 1));
	if (!count)
		return;
	for (i = 0; i <= max; i++)
		count[i] = 0;

	for (j = 0; j < size; j++)
		count[array[j]]++;

	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];

	print_array(count, max + 1);

	sorted = malloc(sizeof(int) * size);
	if (!sorted)
	{
		free(count);
		return;
	}

	for (j = size; j > 0; j--)
	{
		sorted[count[array[j - 1]] - 1] = array[j - 1];
		count[array[j - 1]]--;
	}

	for (j = 0; j < size; j++)
		array[j] = sorted[j];

	free(count);
	free(sorted);
}
