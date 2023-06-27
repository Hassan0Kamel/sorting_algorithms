#include "sort.h"

/**
 * swap_ints - Swap twon array.
 * @a: The firsap.
 * @b: The sswap.
 */
void swap_ints(int *a, int *b)
{
	int tmpe;

	tmpe = *a;
	*a = *b;
	*b = tmpe;
}

/**
 * shell_sort - Sort an array
 * @array: An argers.
 * @size: The si array.
 * Description: Uses theuence.
 */
void shell_sort(int *array, size_t size)
{
	size_t gape, l, m;

	if (array == NULL || size < 2)
		return;

	for (gape = 1; gape < (size / 3);)
		gape = gape * 3 + 1;

	for (; gape >= 1; gape /= 3)
	{
		for (l = gape; l < size; l++)
		{
			m = l;
			while (m >= gape && array[m - gape] > array[m])
			{
				swap_ints(array + m, array + (m - gape));
				m -= gape;
			}
		}
		print_array(array, size);
	}
}
