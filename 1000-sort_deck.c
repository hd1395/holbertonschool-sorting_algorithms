#include "sort.h"

/**
 * swap_node_ahead - Swaps a node with the node ahead of it
 * @list: Double pointer to the head of the list
 * @tail: Double pointer to the tail of the list
 * @shaker: Pointer to the node being swapped
 */
void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *tmp = (*shaker)->next;

	if ((*shaker)->prev != NULL)
		(*shaker)->prev->next = tmp;
	else
		*list = tmp;

	tmp->prev = (*shaker)->prev;
	(*shaker)->next = tmp->next;

	if (tmp->next != NULL)
		tmp->next->prev = *shaker;
	else
		*tail = *shaker;

	(*shaker)->prev = tmp;
	tmp->next = *shaker;
	*shaker = tmp;
}

/**
 * swap_node_behind - Swaps a node with the node behind it
 * @list: Double pointer to the head of the list
 * @tail: Double pointer to the tail of the list
 * @shaker: Pointer to the node being swapped
 */
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *tmp = (*shaker)->prev;

	if ((*shaker)->next != NULL)
		(*shaker)->next->prev = tmp;
	else
		*tail = tmp;

	tmp->next = (*shaker)->next;
	(*shaker)->prev = tmp->prev;

	if (tmp->prev != NULL)
		tmp->prev->next = *shaker;
	else
		*list = *shaker;

	(*shaker)->next = tmp;
	tmp->prev = *shaker;
	*shaker = tmp;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list using cocktail shaker sort
 * @list: Double pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *shaker;
	int shaken_not_stirred = 0;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (shaken_not_stirred == 0)
	{
		shaken_not_stirred = 1;
		for (shaker = *list; shaker != tail; shaker = shaker->next)
		{
			if (shaker->n > shaker->next->n)
			{
				swap_node_ahead(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				shaken_not_stirred = 0;
			}
		}
		for (shaker = shaker->prev; shaker != *list;
		     shaker = shaker->prev)
		{
			if (shaker->n < shaker->prev->n)
			{
				swap_node_behind(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				shaken_not_stirred = 0;
			}
		}
	}
}
