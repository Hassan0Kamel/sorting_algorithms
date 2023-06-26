#include "sort.h"

void swap_ints(int *a, int *b);
void max_heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

/**
 * swap_ints - in an array.
 * @a: The firsto swap.
 * @b: The sto swap.
 */
void swap_ints(int *a, int *b)
{
	int tmpe;

	tmpe = *a;
	*a = *b;
	*b = tmpe;
}

/**
 * max_heapify - Turn a biny heap.
 * @array: Anting a binary tree.
 * @size: The siztree.
 * @base: The ind the tree.
 * @root: The rotree.
 */
void max_heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t lefte, righte, largee;

	lefte = 2 * root + 1;
	righte = 2 * root + 2;
	largee = root;

	if (lefte < base && array[lefte] > array[largee])
		largee = lefte;
	if (righte < base && array[righte] > array[largee])
		largee = righte;

	if (largee != root)
	{
		swap_ints(array + root, array + largee);
		print_array(array, size);
		max_heapify(array, size, base, largee);
	}
}

/**
 * heap_sort - Sort an array
 * @array: An a integers.
 * @size: The si array.
 * Description: Implements
 */
void heap_sort(int *array, size_t size)
{
	int j;

	if (array == NULL || size < 2)
		return;

	for (j = (size / 2) - 1; j >= 0; j--)
		max_heapify(array, size, size, j);

	for (j = size - 1; j > 0; j--)
	{
		swap_ints(array, array + j);
		print_array(array, size);
		max_heapify(array, size, j, 0);
	}
}
