#include "sort.h"

/**
 * swap_nodes - Swap two nodes in a doubly-linked list.
 *
 * @list: A pointer to the head of the doubly-linked list.
 * @node1: A pointer to the first node to swap.
 * @node2: second node to swap.
 *
 * Returns: Nothing
 */

void swap_nodes(listint_t **list, listint_t **node1, listint_t *node2)
{
	if (list == NULL || *list == NULL || node1 == NULL
			|| *node1 == NULL || node2 == NULL || *node1 == node2)
		return;

	if ((*node1)->prev != NULL)
		(*node1)->prev->next = node2;
	else
		*list = node2;

	node2->prev = (*node1)->prev;
	(*node1)->prev = node2;

	if (node2->next != NULL)
		node2->next->prev = *node1;

	(*node1)->next = node2->next;
	node2->next = *node1;

	*node1 = node2->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list using the
 * insertion sort algorithm
 *
 * @list: A pointer to the head of the doubly linked list
 *
 * Returns: Nothing
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *marker, *next_node;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (current = (*list)->next; current != NULL; current = next_node)
	{
		next_node = current->next;
		marker = current->prev;

		while (marker != NULL && current->n < marker->n)
		{
			swap_nodes(list, &marker, current);
			print_list((const listint_t *)*list);
			marker = current->prev;
		}
	}
}
