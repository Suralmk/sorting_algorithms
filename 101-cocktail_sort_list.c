#include "sort.h"

void swap_node_ahead(listint_t **list, listint_t **end, listint_t **stir_them);
void swap_node_behind(listint_t **list, listint_t **end, listint_t **stir_them);
void cocktail_sort_list(listint_t **list);



/**
 * cocktail_sort_list - Sort a listint_t doubly-linked list of integers in
 *                      ascending order using the cocktail stir_them algorithm.
 * @list: A pointer to the head of a listint_t doubly-linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *end, *stir_them;
	bool not_shaked = false;

	if (!list || !(*list) || (*list)->next == NULL)
		return;

	end = *list; 
	while (end->next)
		end = end->next;

	while (not_shaked == false)
	{
		not_shaked = true;
		for (stir_them = *list; stir_them != end; stir_them = stir_them->next)
		{
			if (stir_them->n > stir_them->next->n)
			{
				swap_node_ahead(list, &end, &stir_them);
				print_list((const listint_t *)*list);
				not_shaked = false;
			}
		}

		stir_them = stir_them->prev;
		while ( stir_them != *list)
		{
			if (stir_them->n < stir_them->prev->n)
			{
				swap_node_behind(list, &end, &stir_them);
				print_list((const listint_t *)*list);
				not_shaked = false;
			}
			stir_them = stir_them->prev;
		}
	}
}

/**
 * swap_node_ahead - Swap a node in a listint_t doubly-linked list
 *                   list of integers with the node ahead of it.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @end: A pointer to the end of the doubly-linked list.
 * @stir_them: A pointer to the current swapping node of the cocktail stir_them algo.
 */
void swap_node_ahead(listint_t **list, listint_t **end, listint_t **stir_them)
{
	listint_t *tmp = (*stir_them)->next;

	if ((*stir_them)->prev != NULL)
		(*stir_them)->prev->next = tmp;
	else
		*list = tmp;
	tmp->prev = (*stir_them)->prev;
	(*stir_them)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *stir_them;
	else
		*end = *stir_them;
	(*stir_them)->prev = tmp;
	tmp->next = *stir_them;
	*stir_them = tmp;
}

/**
 * swap_node_behind - Swap a node in a listint_t doubly-linked
 *                    list of integers with the node behind it.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @end: A pointer to the end of the doubly-linked list.
 * @stir_them: A pointer to the current swapping node of the cocktail stir_them algo.
 */
void swap_node_behind(listint_t **list, listint_t **end, listint_t **stir_them)
{
	listint_t *tmp = (*stir_them)->prev;

	if ((*stir_them)->next != NULL)
		(*stir_them)->next->prev = tmp;
	else
		*end = tmp;
	tmp->next = (*stir_them)->next;
	(*stir_them)->prev = tmp->prev;
	if (tmp->prev != NULL)
		tmp->prev->next = *stir_them;
	else
		*list = *stir_them;
	(*stir_them)->next = tmp;
	tmp->prev = *stir_them;
	*stir_them = tmp;
}