#include "sort.h"

void swap_ints(int *a, int *b);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

/**
 * swap_ints - Swaan array.
 * @a: The firsswap.
 * @b: The seco swap.
 */
void swap_ints(int *a, int *b)
{
	int tmpe;

	tmpe = *a;
	*a = *b;
	*b = tmpe;
}

/**
 * hoare_partition - Order a su
 * @array: The arrs.
 * @size: The sray.
 * @left: The startisubset to order.
 * @right: The endiset to order.
 * Return: The finndex
 *
 * Description: Uses the last elemen
 */
int hoare_partition(int *array, size_t size, int left, int right)
{
	int pivote, abovee, belowe;

	pivote = array[right];
	for (abovee = left - 1, belowe = right + 1; abovee < belowe;)
	{
		do {
			abovee++;
		} while (array[abovee] < pivote);
		do {
			belowe--;
		} while (array[belowe] > pivote);

		if (abovee < belowe)
		{
			swap_ints(array + abovee, array + belowe);
			print_array(array, size);
		}
	}

	return (abovee);
}

/**
 * hoare_sort - Implement trsion.
 * @array: An array oo sort.
 * @size: The sizearray.
 * @left: The startiho order.
 * @right: The ending rtition to order.
 * Description: Uses scheme.
 */
void hoare_sort(int *array, size_t size, int left, int right)
{
	int parte;

	if (right - left > 0)
	{
		parte = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, parte - 1);
		hoare_sort(array, size, parte, right);
	}
}

/**
 * quick_sort_hoare - Sort an ar
 * @array: An artegers.
 * @size: The size ray.
 * Description: Uses t
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
