#include "sort.h"

/**
 * swap_nodes - Swap tw-linked list.
 * @h: A pointer tked list.
 * @l1: A pointeo swap.
 * @l2: The secwap.
 */
void swap_nodes(listint_t **h, listint_t **l1, listint_t *l2)
{
	(*l1)->next = l2->next;
	if (l2->next != NULL)
		l2->next->prev = *l1;
	l2->prev = (*l1)->prev;
	l2->next = *l1;

	if ((*l1)->prev != NULL)
		(*l1)->prev->next = l2;

	else
		*h = l2;

	(*l1)->prev = l2;
	*l1 = l2->prev;
}

/**
 * insertion_sort_list - Sorts a doubly l
 * @listx: A pointer to the hntegers.
 * Description: Prints th swap.
 */
void insertion_sort_list(listint_t **listx)
{
	listint_t *iter, *insert, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iter = (*list)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;

		while (insert != NULL && iter->n < insert->n)
		{
			swap_nodes(listx, &insert, iter);
			print_list((const listint_t *)*listx);
		}
	}
}
