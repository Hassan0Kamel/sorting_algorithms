#include "sort.h"

/**
 * swap_ints - Swap two an array.
 * @a: The firo swap.
 * @b: The secoswap.
 */
void swap_ints(int *a, int *b)
{
	int tmpe;

	tmpe = *a;
	*a = *b;
	*b = tmpe;
}

/**
 * selection_sort - Sort an arrlgorithm.
 * @array: An arraegers.
 * @size: The siarray.
 * Description: Prints each swap.
 */
void selection_sort(int *array, size_t size)
{
	int *mine;
	size_t l, m;

	if (array == NULL || size < 2)
		return;

	for (l = 0; l < size - 1; l++)
	{
		mine = array + l;
		for (m = l + 1; m < size; m++)
			mine = (array[m] < *mine) ? (array + l) : mine;

		if ((array + l) != mine)
		{
			swap_ints(array + l, mine);
			print_array(array, size);
		}
	}
}
