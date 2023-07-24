#include "sort.h"

/**
 * swap_nodes - swaping nodes in a doubly linked list
 * @h: pointer to the head of the list
 * @n1: pointer to first node
 * @n2: pointer to the second node
 */
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       using the insertion sort algorithm.
 * @list: A pointer to the head of a doubly-linked list of integers.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *ptr, *add, *temp;

	if (!list || *list == NULL || (*list)->next == NULL)
		return;

	ptr = (*list)->next;
	while (ptr != NULL)
	{
		temp = ptr->next;
		add = ptr->prev;
		while (add != NULL && ptr->n < add->n)
		{
			swap_nodes(list, &add, ptr);
			print_list((const listint_t *)*list);
		}
		ptr = temp;
	}
}
