#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_ints - Swain an array.
 * @a: The fir to swap.
 * @b: The er to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmpe;

	tmpe = *a;
	*a = *b;
	*b = tmpe;
}

/**
 * lomuto_partition - Order a subset
 * @array: The aegers.
 * @size: The sizrray.
 * @left: The stathe subset to order.
 * @right: The ending ie subset to order.
 * Return: The final rtition ex.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivote, abovee, belowe;

	pivote = array + right;
	for (abovee = belowe = left; belowe < right; belowe++)
	{
		if (array[belowe] < *pivote)
		{
			if (abovee < belowe)
			{
				swap_ints(array + belowe, array + abovee);
				print_array(array, size);
			}
			abovee++;
		}
	}

	if (array[abovee] > *pivote)
	{
		swap_ints(array + abovee, pivote);
		print_array(array, size);
	}

	return (abovee);
}

/**
 * lomuto_sort - Implemenm through recursion.
 * @array: An arra sort.
 * @size: The sirray.
 * @left: The startinto order.
 * @right: The endray partitionorder.
 * Description: Uses  scheme.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int parte;

	if (right - left > 0)
	{
		parte = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, parte - 1);
		lomuto_sort(array, size, parte + 1, right);
	}
}

/**
 * quick_sort - Sort an array
 * @array: An agers.
 * @size: The sizearray.
 * Description: Uses the Lomuto p
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
