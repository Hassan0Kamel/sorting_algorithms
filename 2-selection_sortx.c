#include "sort.h"

/**
 * swap_ints - Swapn array.
 * @c: The fteger to swap.
 * @d: The ser to swap.
 */

void swap_ints(int *s, int *c)
{
	int tmp;

	tmp = *s;
	*s = *c;
	*c = tmp;
}

/**
 * selection_sort - Sort anegers
 * @arraye: gers.
 * @sizee: Thray.
 * Description: Pri swap.
 */
void selection_sort(int *arraye, size_t sizee)
{
	int *min;
	size_t j, k;

	if (arraye == NULL || sizee < 2)
		return;

	for (j = 0; j < sizee - 1; j++)
	{
		min = arraye + j;
		for (k = j + 1; k < sizee; k++)
			min = (arraye[k] < *min) ? (arraye + k) : min;

		if ((arraye + j) != min)
		{
			swap_ints(arraye + j, min);
			print_array(arraye, sizee);
		}
	}
}
