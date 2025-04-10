#include "sort.h"

/**
 * swap - swaps 2 nodes in a doubly-linked list
 * @n1: address of first node
 * @n2: address of second node
 *
 * Return: void
 */
void swap(listint_t *n1, listint_t *n2)
{
if (n1->prev)
n1->prev->next = n2;
if (n2->next)
n2->next->prev = n1;
n1->next = n2->next;
n2->prev = n1->prev;
n1->prev = n2;
n2->next = n1;

}

/**
 * insertion_sort_list - sorts a doubly linked list of integers in
 *          ascending order using the Insertion sort algorithm
 * @list: address of pointer to head node
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
listint_t *i, *j;

if (!list || !*list || !(*list)->next)
return;
i = (*list)->next;
while (i)
{
j = i;
i = i->next;
while (j && j->prev)
{
if (j->prev->n > j->n)
{
swap(j->prev, j);
if (!j->prev)
*list = j;
print_list((const listint_t *)*list);
}
else
j = j->prev;
}
}
}
