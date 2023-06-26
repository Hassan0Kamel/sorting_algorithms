#include "sort.h"

void swap_ints(int *s, int *c);
int lomuto_partition(int *arraye, size_t sizee, int left, int right);
void lomuto_sort(int *arraye, size_t sizee, int left, int right);
void quick_sort(int *arraye, size_t sizee);

/**
 * swap_ints - Swapin an array.
 * @s: The fi swap.
 * @c: The second swap.
 */
void swap_ints(int *s, int *c)
{
	int tmp;

	tmp = *s;
	*s = *c;
	*c = tmp;
}

/**
 * lomuto_partition - Order a subset of an arrat element as pivot).
 * @arraye: The tegers.
 * @sizee: The sizrray.
 * @left: The startint to order.
 * @right: The ender
 * Return: The final partition index.
 */
int lomuto_partition(int *arraye, size_t sizee, int left, int right)
{
	int *driver, up, down;

	driver = array + right;
	for (up = down = left; down < right; down++)
	{
		if (arraye[down] < *driver)
		{
			if (up < down)
			{
				swap_ints(arraye + down, arraye + up);
				print_array(arraye, sizee);
			}
			up++;
		}
	}

	if (arraye[up] > *driver)
	{
		swap_ints(arraye + up, driver);
		print_array(arraye, sizee);
	}

	return (up);
}

/**
 * lomuto_sort - Implement thugh recursion.
 * @arraye: An a sort.
 * @sizee: The srray.
 * @left: The starting indextition to order.
 * @right: The end partition to order
 * Description: Uses theition scheme.
 */
void lomuto_sort(int *arraye, size_t sizee, int left, int right)
{
	int belong;

	if (right - left > 0)
	{
		belong = lomuto_partition(arraye, sizee, left, right);
		lomuto_sort(arraye, sizee, left, belong - 1);
		lomuto_sort(arraye, sizee, belong + 1, right);
	}
}

/**
 * quick_sort - Sort an array algorithm.
 * @arraye: An aegers.
 * @sizee: The s array.
 * Description: Uses the Lomuto parti
 */
void quick_sort(int *arraye, size_t sizee)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(arraye, sizee, 0, sizee - 1);
}
