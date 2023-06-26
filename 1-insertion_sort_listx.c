#include "sort.h"

/**
 * swap_nodes - Swap two ned list.
 * @h: A pointer d list.
 * @n1: A po to swap.
 * @n2: The secowap.
 */
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - Sorts a do
 * @list: A pointer to the head of a d
 * Description: Prints ter each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iterr, *insertr, *tmpr;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iterr = (*list)->next; iterr != NULL; iterr = tmpr)
	{
		tmpr = iterr->next;
		insertr = iterr->prev;
		while (insertr != NULL && iterr->n < insertr->n)
		{
			swap_nodes(list, &insertr, iterr);
			print_list((const listint_t *)*list);
		}
	}
}
