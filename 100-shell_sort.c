#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order
 *              using the Shell sort algorithm and Knuth sequence.
 * @array: Pointer to the array to sort
 * @size: Number of elements in the array
 *
 * Return: Nothing
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j;
	int temp;

	if (!array || size < 2)
		return;

	/* Compute initial Knuth sequence value */
	while (gap < size / 3)
		gap = gap * 3 + 1;

	/* Perform shell sort using decreasing gaps */
	while (gap >= 1)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
				array[j] = array[j - gap];
			array[j] = temp;
		}
		print_array(array, size);
		gap = (gap - 1) / 3;
	}
}
