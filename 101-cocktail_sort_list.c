#include "sort.h"

/**
 * swap_nodes - Swaps two adjacent nodes of a doubly linked list.
 *
 * @left: Pointer to the left node.
 * @right: Pointer to the right node.
 * @list: Pointer to the doubly linked list.
 */
void swap_nodes(listint_t *left, listint_t *right, listint_t **list)
{
	listint_t *prev, *next;

	prev = left->prev;
	next = right->next;
	if (prev)
		prev->next = right;
	else
		*list = right;
	right->prev = prev;
	left->prev = right;
	right->next = left;
	left->next = next;
	if (next)
		next->prev = left;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending
 *                      order using the Cocktail shaker sort algorithm.
 *
 * @list: Pointer to the doubly linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *start, *end, *current;
	int swapped = 0;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	start = *list;
	end = NULL;

	do {
		swapped = 0;
		for (current = start; current != end; current = current->next)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(current, current->next, list);
				print_list(*list);
				swapped = 1;
			}
		}
		if (swapped == 0)
			break;
		end = current->prev;
		swapped = 0;
		for (current = end; current != start; current = current->prev)
			if (current->n < current->prev->n)
			{
				swap_nodes(current->prev, current, list);
				print_list(*list);
				swapped = 1;
			}
		start = current->next;
	} while (swapped);
}
