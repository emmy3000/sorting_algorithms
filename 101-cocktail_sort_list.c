#include "sort.h"


/**
 * swap_node_ahead - swaps node with next node
 *
 * @list: head of the list
 * @tail: tail of the list
 * @current: current node
 *
 * Return: Nothing
 **/

void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **current)
{
	listint_t *temp = (*current)->next;

	if ((*current)->prev != NULL)
		(*current)->prev->next = temp;
	else
		*list = temp;

	temp->prev = (*current)->prev;
	(*current)->next = temp->next;

	if (temp->next != NULL)
		temp->next->prev = *current;
	else
		*tail = *current;

	(*current)->prev = temp;
	temp->next = *current;
	*current = temp;
}


/**
 * swap_node_behind - Swaps node with previous node
 *
 * @list: head of the list
 * @tail: tail of the list
 * @current: current node
 *
 * Return: Nothing
 **/

void swap_node_behind(listint_t **list, listint_t **tail, listint_t **current)
{
	listint_t *temp = (*current)->prev;

	if ((*current)->next != NULL)
		(*current)->next->prev = temp;
	else
		*tail = temp;

	temp->next = (*current)->next;
	(*current)->prev = temp->prev;

	if (temp->prev != NULL)
		temp->prev->next = *current;
	else
		*list = *current;

	(*current)->next = temp;
	temp->prev = *current;
	*current = temp;
}


/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the Cocktail shaker sort algorithm
 *
 * @list: head of the list
 *
 * Return: Nothing
 **/

void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *current;
	bool is_sorted = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (is_sorted == false)
	{
		is_sorted = true;

		for (current = *list; current != tail; current = current->next)
		{
			if (current->n > current->next->n)
			{
				swap_node_ahead(list, &tail, &current);
				print_list(*list);
				is_sorted = false;
			}
		}

		for (current = current->prev; current != *list; current = current->prev)
		{
			if (current->n < current->prev->n)
			{
				swap_node_behind(list, &tail, &current);
				print_list(*list);
				is_sorted = false;
			}
		}
	}
}
