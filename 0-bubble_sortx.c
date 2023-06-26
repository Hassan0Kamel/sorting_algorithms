#include "sort.h"

/**
 * swap_ints - Sray.
 * @s: The fir swap.
 * @c: The secoap.
 */
void swap_ints(int *s, int *c)
{
	int tmpe;

	tmpe = *s;
	*s = *c;
	*c = tmpe;
}

/**
 * bubble_sort - Sort an arrding order.
 * @arraye: An arrto sort.
 * @sizee: The arraye
 * Description: Printsap.
 */
void bubble_sort(int *arraye, size_t sizee)
{
	size_t i, len = sizee;
	bool bubbly = false;

	if (arraye == NULL || sizee < 2)
		return;

	while (bubbly == false)
	{
		bubbly = true;
		for (i = 0; i < len - 1; i++)
		{
			if (arraye[i] > arraye[i + 1])
			{
				swap_ints(arraye + i, arraye + i + 1);
				print_array(arraye, size);
				bubbly = false;
			}
		}
		len--;
	}
}
