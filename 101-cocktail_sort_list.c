#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Pointer to the head of the list
 * @node1: First node
 * @node2: Second node
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev)
		node1->prev->next = node2;
	else
		*list = node2;

	if (node2->next)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list using Cocktail shaker sort
 * @list: Pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *start, *end;

	if (!list || !*list || !(*list)->next)
		return;

	start = *list;
	while (swapped)
	{
		swapped = 0;

		while (start->next)
		{
			if (start->n > start->next->n)
			{
				swap_nodes(list, start, start->next);
				swapped = 1;
				print_list(*list);
			}
			else
				start = start->next;
		}

		end = start;
		while (end->prev)
		{
			if (end->n < end->prev->n)
			{
				swap_nodes(list, end->prev, end);
				swapped = 1;
				print_list(*list);
			}
			else
				end = end->prev;
		}
		start = end;
	}
}
