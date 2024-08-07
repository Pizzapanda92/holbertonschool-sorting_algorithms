#include "sort.h"
#include <stdio.h>

/**
 * swap_nodes - Swap two adjacent nodes in a doubly linked list
 * @list: Pointer to the head of the list
 * @node1: First node to swap
 * @node2: Second node to swap
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
 * insertion_sort_list - Sorts a doubly linked list of
 * integers in ascending order
 * using the Insertion sort algorithm
 * @list: Double pointer to the head of the doubly linked list
 */

void insertion_sort_list(listint_t **list)
{
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	listint_t *current = (*list)->next;

	while (current != NULL)
	{
		listint_t *next_node = current->next;

		while (current->prev != NULL && current->n < current->prev->n)
		{
			swap_nodes(list, current->prev, current);
			print_list(*list);

		}
		current = next_node;
	}

}
