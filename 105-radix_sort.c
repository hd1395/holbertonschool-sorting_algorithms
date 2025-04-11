#include "sort.h"

/**
 * get_max - Finds the max value in array
 * @array: The array
 * @size: Size of array
 * Return: Max value
 */
int get_max(int *array, size_t size)
{
	size_t i;
	int max = array[0];

	for (i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];
	return (max);
}

/**
 * radix_sort - Sorts array using LSD Radix Sort
 * @array: The array
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size)
{
	int *output, count[10] = {0};
	int max, exp, i;
	size_t j;

	if (!array || size < 2)
		return;

	max = get_max(array, size);
	output = malloc(sizeof(int) * size);
	if (!output)
		return;

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		for (i = 0; i < 10; i++)
			count[i] = 0;
		for (j = 0; j < size; j++)
			count[(array[j] / exp) % 10]++;
		for (i = 1; i < 10; i++)
			count[i] += count[i - 1];
		for (j = size; j > 0; j--)
			output[--count[(array[j - 1] / exp) % 10]] = array[j - 1];
		for (j = 0; j < size; j++)
			array[j] = output[j];
		print_array(array, size);
	}
	free(output);
}
