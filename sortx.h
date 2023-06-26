#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

void swap_ints(int *s, int *c)
void bubble_sort(int *arraye, size_t sizee)
void swap_nodes(listint_t **h, listint_t **l1, listint_t *l2)
void insertion_sort_list(listint_t **listx)
void selection_sort(int *arraye, size_t sizee)
int lomuto_partition(int *arraye, size_t sizee, int left, int right);
void lomuto_sort(int *arraye, size_t sizee, int left, int right);
void quick_sort(int *arraye, size_t sizee);

#endif /* SORT_H */
