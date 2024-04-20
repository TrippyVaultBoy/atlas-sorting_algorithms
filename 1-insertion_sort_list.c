#include "sort.h"

/**
 * node_swap- swaps two nodes in a doubly linked list
 * @head: pointer to head of the list
 * @node1: first node
 * @node2: second node
*/

void node_swap(listint_t **head, listint_t **node1, listint_t *node2)
{
	(*node1)->next = node2->next;

	if (node2->next != NULL)
	{
		node2->next->prev = *node1;
	}

	node2->prev = (*node1)->prev;
	node2->next = *node1;

	if ((*node1)->prev != NULL)
	{
		(*node1)->prev->next = node2;
	}
	else
	{
		*head = node2;
	}

	(*node1)->prev = node2;
	*node1 = node2->prev;
}

/**
 * insertion_sort_list- sorts a doubly linked list with insertion sort algorithm
 * @list: pointer to input list
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *current;
	listint_t *temp;
	listint_t *back_node;

	if (list == NULL || *list == NULL)
	{
		return;
	}

	for (current = (*list)->next; current != NULL; current = temp)
	{
		temp = current->next;
		back_node = current->prev;

		while (back_node != NULL && current->n < back_node->n)
		{
			node_swap(list, &back_node, current);
			print_list(*list);
		}
	}
}
