#include "sort.h"

/**
 * swap_ints - Swaps two integers
 * @a: first int
 * @b: second int
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	if (a == b)
		return;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - Partitions the array using Lomuto scheme
 * @array: The array to partition
 * @low: Start index
 * @high: End index
 * @size: Size of array (for printing)
 * Return: Index of pivot after partition
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap_ints(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}

	if ((i + 1) != high && array[i + 1] != array[high])
	{
		swap_ints(&array[i + 1], &array[high]);
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * quick_sort_recursive - Helper function for quick sort
 * @array: The array
 * @low: Start index
 * @high: End index
 * @size: Size of array (for printing)
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int pi;

	if (low < high)
	{
		pi = lomuto_partition(array, low, high, size);
		quick_sort_recursive(array, low, pi - 1, size);
		quick_sort_recursive(array, pi + 1, high, size);
	}
}

/**
 * quick_sort - Sorts array using Quick sort (Lomuto partition)
 * @array: The array to sort
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}
