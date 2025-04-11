#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

/*Comparison direction macros for bitonic sort*/
#define UP 0
#define DOWN 1

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
const int n;
struct listint_s *prev;
struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void selection_sort(int *array, size_t size);
void swap_ints(int *a, int *b);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);
/**
 * split - Recursively splits array and merges it
 * @a: Array to sort
 * @t: Temp buffer
 * @l: Left index
 * @r: Right index
 */
void split(int *a, int *t, size_t l, size_t r);

/**
 * merge - Merges two subarrays into one
 * @a: Array to sort
 * @t: Temp buffer
 * @l: Left start
 * @m: Middle
 * @r: Right end
 */
void merge(int *a, int *t, size_t l, size_t m, size_t r);
#endif /* SORT_H */
