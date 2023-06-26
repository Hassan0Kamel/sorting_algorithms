#include "sort.h"

void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shaker);
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker);
void cocktail_sort_list(listint_t **list);

/**
 * swap_node_ahead - Swap a nod
 * @list: A pointer to  integers.
 * @tail: A pointer linked list.
 * @shaker: A poine of the cocktail shaker algo.
 */
void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *tmpe = (*shaker)->next;

	if ((*shaker)->prev != NULL)
		(*shaker)->prev->next = tmpe;
	else
		*list = tmpe;
	tmpe->prev = (*shaker)->prev;
	(*shaker)->next = tmpe->next;
	if (tmpe->next != NULL)
		tmpe->next->prev = *shaker;
	else
		*tail = *shaker;
	(*shaker)->prev = tmpe;
	tmpe->next = *shaker;
	*shaker = tmpe;
}

/**
 * swap_node_behind - Swap a node in
 * @list: A pointer st of integers.
 * @tail: A pointer tlinked list.
 * @shaker: A pointer tocktail shaker algo.
 */
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *tmpe = (*shaker)->prev;

	if ((*shaker)->next != NULL)
		(*shaker)->next->prev = tmpe;
	else
		*tail = tmpe;
	tmpe->next = (*shaker)->next;
	(*shaker)->prev = tmpe->prev;
	if (tmpe->prev != NULL)
		tmpe->prev->next = *shaker;
	else
		*list = *shaker;
	(*shaker)->next = tmpe;
	tmpe->prev = *shaker;
	*shaker = tmpe;
}

/**
 * cocktail_sort_list - Sort a listi
 * @list: A pointer tolist.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *shaker;
	bool shaken_not_stirred = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (shaken_not_stirred == false)
	{
		shaken_not_stirred = true;
		for (shaker = *list; shaker != tail; shaker = shaker->next)
		{
			if (shaker->n > shaker->next->n)
			{
				swap_node_ahead(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
		for (shaker = shaker->prev; shaker != *list;
				shaker = shaker->prev)
		{
			if (shaker->n < shaker->prev->n)
			{
				swap_node_behind(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
	}
}
