#include "sort.h"

/**
 * swap - Swap two integers
 * @a: pointer to first integer
 * @b: pointer to second integer
 */
void swap(int *a, int *b)
{
	int temp;

	if (*a != *b)
	{
		temp = *a;
		*a = *b;
		*b = temp;
	}
}

/**
 * bitonic_merge - Merge bitonic sequence in given direction
 * @array: array to sort
 * @low: start index
 * @count: number of elements
 * @dir: sorting direction (1 for UP, 0 for DOWN)
 * @size: size of full array
 */
void bitonic_merge(int *array, size_t low, size_t count, int dir, size_t size)
{
	size_t i, k;

	if (count < 2)
		return;

	k = count / 2;
	for (i = low; i < low + k; i++)
	{
		if ((dir && array[i] > array[i + k]) ||
		    (!dir && array[i] < array[i + k]))
			swap(&array[i], &array[i + k]);
	}

	bitonic_merge(array, low, k, dir, size);
	bitonic_merge(array, low + k, k, dir, size);
}

/**
 * bitonic_seq - Recursively build bitonic sequence
 * @array: array to sort
 * @low: starting index
 * @count: number of elements
 * @dir: sorting direction (1 for UP, 0 for DOWN)
 * @size: full array size
 */
void bitonic_seq(int *array, size_t low, size_t count, int dir, size_t size)
{
	size_t k;

	if (count < 2)
		return;

	k = count / 2;

	printf("Merging [%lu/%lu] (%s):\n", count, size, dir ? "UP" : "DOWN");
	print_array(array + low, count);

	bitonic_seq(array, low, k, 1, size);
	bitonic_seq(array + k, low + k, k, 0, size);
	bitonic_merge(array, low, count, dir, size);

	printf("Result [%lu/%lu] (%s):\n", count, size, dir ? "UP" : "DOWN");
	print_array(array + low, count);
}

/**
 * bitonic_sort - Sort array using Bitonic Sort algorithm
 * @array: array to sort
 * @size: number of elements
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	bitonic_seq(array, 0, size, 1, size);
}
