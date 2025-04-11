#include "sort.h"
/**
 * merge_sort - Sorts array using merge sort
 * @array: Array to sort
 * @size: Size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *tmp;

	if (!array || size < 2)
		return;

	tmp = malloc(sizeof(int) * size);
	if (!tmp)
		return;

	split(array, tmp, 0, size);
	free(tmp);
}

/**
 * split - Recursively splits and merges array
 * @a: Array to sort
 * @t: Temp buffer
 * @l: Left index
 * @r: Right index
 */
void split(int *a, int *t, size_t l, size_t r)
{
	size_t m;

	if (r - l > 1)
	{
		m = (l + r) / 2;

		split(a, t, l, m), split(a, t, m, r);
		printf("Merging...\n[left]: "), print_array(a + l, m - l);
		printf("[right]: "), print_array(a + m, r - m);
		merge(a, t, l, m, r);
		printf("[Done]: "), print_array(a + l, r - l);
	}
}

/**
 * merge - Merges two sorted subarrays
 * @a: Array
 * @t: Temp buffer
 * @l: Left
 * @m: Mid
 * @r: Right
 */
void merge(int *a, int *t, size_t l, size_t m, size_t r)
{
	size_t i = l, j = m, k = l;

	while (k < r)
		t[k++] = (j == r || (i < m && a[i] <= a[j])) ? a[i++] : a[j++];
	for (k = l; k < r; k++)
		a[k] = t[k];
}
