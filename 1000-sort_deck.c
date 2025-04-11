#include "deck.h"

/**
 * card_value - Returns the index of a card based on value
 * @value: The string value of the card ("Ace" to "King")
 * Return: Integer index from 0 (Ace) to 12 (King)
 */
int card_value(const char *value)
{
	const char *ranks[] = {
		"Ace", "2", "3", "4", "5", "6", "7",
		"8", "9", "10", "Jack", "Queen", "King"
	};
	int i;

	for (i = 0; i < 13; i++)
	{
		if (strcmp(value, ranks[i]) == 0)
			return (i);
	}
	return (-1);
}

/**
 * compare_cards - Compare two cards in deck
 * @a: First deck node
 * @b: Second deck node
 * Return: Negative if a < b, 0 if equal, positive if a > b
 */
int compare_cards(const deck_node_t *a, const deck_node_t *b)
{
	if (a->card->kind != b->card->kind)
		return (a->card->kind - b->card->kind);

	return (card_value(a->card->value) - card_value(b->card->value));
}

/**
 * swap_nodes - Swap two nodes in a doubly linked list
 * @deck: Pointer to head pointer
 * @a: First node
 * @b: Second node
 */
void swap_nodes(deck_node_t **deck, deck_node_t *a, deck_node_t *b)
{
	if (a->prev)
		a->prev->next = b;
	else
		*deck = b;

	if (b->next)
		b->next->prev = a;

	a->next = b->next;
	b->prev = a->prev;

	a->prev = b;
	b->next = a;
}

/**
 * sort_deck - Sorts a deck of cards using insertion sort
 * @deck: Pointer to the head pointer of the deck
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *current, *insertion;

	if (!deck || !*deck || !(*deck)->next)
		return;

	current = (*deck)->next;
	while (current)
	{
		insertion = current;
		current = current->next;

		while (insertion->prev &&
		       compare_cards(insertion->prev, insertion) > 0)
		{
			swap_nodes(deck, insertion->prev, insertion);
		}
	}
}
