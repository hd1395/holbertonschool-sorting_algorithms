#include "sort.h"
/**
 * counting_sort - Counting sort algorithm
 * @array: Array to sort
 * @size: Size of array
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sorted, max, i;
	size_t j;

	if (!array || size < 2)
		return;

	for (max = array[0], j = 1; j < size; j++)
		if (array[j] > max)
			max = array[j];

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
		return (free(count), (void)0);
	for (j = size; j > 0; j--)
		sorted[--count[array[j - 1]]] = array[j - 1];
	for (j = 0; j < size; j++)
		array[j] = sorted[j];
	free(count);
	free(sorted);
}
