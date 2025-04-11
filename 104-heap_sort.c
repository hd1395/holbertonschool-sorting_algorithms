#include "sort.h"

/**
 * heapify - Maintains the heap property
 * @array: Array to sort
 * @size: Full array size (for print)
 * @n: Heap size
 * @i: Current index
 */
void heapify(int *array, size_t size, size_t n, size_t i)
{
	size_t largest = i, l = 2 * i + 1, r = 2 * i + 2;
	int tmp;

	if (l < n && array[l] > array[largest])
		largest = l;
	if (r < n && array[r] > array[largest])
		largest = r;
	if (largest != i)
	{
		tmp = array[i], array[i] = array[largest], array[largest] = tmp;
		print_array(array, size);
		heapify(array, size, n, largest);
	}
}

/**
 * heap_sort - Sorts array using Heap Sort
 * @array: Array to sort
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
	int tmp;
	ssize_t i;

	if (!array || size < 2)
		return;

	for (i = (size - 2) / 2; i >= 0; i--)
		heapify(array, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
		tmp = array[0], array[0] = array[i], array[i] = tmp;
		print_array(array, size);
		heapify(array, size, i, 0);
	}
}
