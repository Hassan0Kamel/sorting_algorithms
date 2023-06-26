#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

/**
 * swap_ints - Sray.
 * @s: The fir swap.
 * @c: The secoap.
 */
void swap_ints(int *s, int *c)

/**
 * bubble_sort - Sort an arrding order.
 * @arraye: An arrto sort.
 * @sizee: The arraye
 * Description: Printsap.
 */

void bubble_sort(int *arraye, size_t sizee)

/**
 * swap_nodes - Swap tw-linked list.
 * @h: A pointer tked list.
 * @l1: A pointeo swap.
 * @l2: The secwap.
 */

void swap_nodes(listint_t **h, listint_t **l1, listint_t *l2)

/**
 * insertion_sort_list - Sorts a doubly l
 * @listx: A pointer to the hntegers.
 * Description: Prints th swap.
 */

void insertion_sort_list(listint_t **listx)

/**
 * selection_sort - Sort anegers
 * @arraye: gers.
 * @sizee: Thray.
 * Description: Pri swap.
 */


void selection_sort(int *arraye, size_t sizee)

/**
 * lomuto_partition - Order a subset of an arrat element as pivot).
 * @arraye: The tegers.
 * @sizee: The sizrray.
 * @left: The startint to order.
 * @right: The ender
 * Return: The final partition index.
 */

int lomuto_partition(int *arraye, size_t sizee, int left, int right);

/**
 * lomuto_sort - Implement thugh recursion.
 * @arraye: An a sort.
 * @sizee: The srray.
 * @left: The starting indextition to order.
 * @right: The end partition to order
 * Description: Uses theition scheme.
 */


void lomuto_sort(int *arraye, size_t sizee, int left, int right);

/**
 * quick_sort - Sort an array algorithm.
 * @arraye: An aegers.
 * @sizee: The s array.
 * Description: Uses the Lomuto parti
 */


void quick_sort(int *arraye, size_t sizee);


#endif /* SORT_H */
