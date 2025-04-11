#include "sort.h"

/**
 * swap - Swaps two integers and prints array
 * @a: First int
 * @b: Second int
 * @array: Array to print
 * @size: Size of array
 */
void swap(int *a, int *b, int *array, size_t size)
{
	int tmp;

	if (*a != *b)
	{
		tmp = *a;
		*a = *b;
		*b = tmp;
		print_array(array, size);
	}
}

/**
 * bitonic_merge - Merges subarray in given direction
 * @array: Array
 * @low: Start index
 * @count: Count of elements
 * @dir: 1 for UP, 0 for DOWN
 * @size: Size of array
 */
void bitonic_merge(int *array, size_t low, size_t count, int dir, size_t size)
{
	size_t i;
	size_t k;

	if (count < 2)
		return;

	k = count / 2;
	for (i = 0; i < k; i++)
	{
		if ((dir && array[low + i] > array[low + i + k]) ||
		    (!dir && array[low + i] < array[low + i + k]))
		{
			swap(&array[low + i], &array[low + i + k], array, size);
		}
	}

	bitonic_merge(array, low, k, dir, size);
	bitonic_merge(array, low + k, k, dir, size);
}

/**
 * bitonic_seq - Recursively creates bitonic sequence
 * @array: Array
 * @low: Start index
 * @count: Count of elements
 * @dir: Direction
 * @size: Size of array
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
	bitonic_seq(array, low + k, k, 0, size);
	bitonic_merge(array, low, count, dir, size);

	printf("Result [%lu/%lu] (%s):\n", count, size, dir ? "UP" : "DOWN");
	print_array(array + low, count);
}

/**
 * bitonic_sort - Sorts an array using Bitonic Sort
 * @array: Array
 * @size: Size of array
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	bitonic_seq(array, 0, size, 1, size);
}
