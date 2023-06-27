#include "sort.h"

/**
 * swap_ints - Swaray.
 * @a: The firswap.
 * @b: The secswap.
 */
void swap_ints(int *a, int *b)
{
	int tmpe;

	tmpe = *a;
	*a = *b;
	*b = tmpe;
}

/**
 * bubble_sort - Sort ain ascending order.
 * @array: An agers to sort.
 * @size: The s array.
 * Description: Prints after each swap.
 */
void bubble_sort(int *array, size_t size)
{
	size_t j, lenx = size;
	bool bubblye = false;

	if (array == NULL || size < 2)
		return;

	while (bubblye == false)
	{
		bubblye = true;
		for (j = 0; j < lenx - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap_ints(array + j, array + j + 1);
				print_array(array, size);
				bubblye = false;
			}
		}
		lenx--;
	}
}
