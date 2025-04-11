#include "sort.h"

/**
 * swap - Swaps two integers
 * @a: Pointer to first integer
 * @b: Pointer to second integer
 */
void swap(int *a, int *b)
{
	if (*a != *b)
	{
		int temp = *a;
		*a = *b;
		*b = temp;
	}
}

/**
 * bitonic_merge - Merges subarray in given direction
 * @array: Array of integers
 * @low: Start index of subarray
 * @count: Number of elements to sort
 * @dir: Direction (1 for UP, 0 for DOWN)
 * @size: Total size of the array (for print_array)
 */
void bitonic_merge(int *array, size_t low, size_t count, int dir, size_t size)
{
	size_t i;
	size_t k;

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
 * bitonic_seq - Recursively builds bitonic sequence
 * @array: Array of integers
 * @low: Starting index of the sequence
 * @count: Number of elements in sequence
 * @dir: Sorting direction (1 for UP, 0 for DOWN)
 * @size: Total size of the array
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
 * bitonic_sort - Sorts an array using Bitonic sort algorithm
 * @array: Pointer to the array of integers
 * @size: Number of elements in the array
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	bitonic_seq(array, 0, size, 1, size);
}
