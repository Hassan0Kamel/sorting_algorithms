#include "sort.h"

void swap_ints(int *a, int *b);
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow);
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow);
void bitonic_sort(int *array, size_t size);

/**
 * swap_ints -in an array.
 * @a: The firsto swap.
 * @b: The sewap.
 */
void swap_ints(int *a, int *b)
{
	int tmpe;

	tmpe = *a;
	*a = *b;
	*b = tmpe;
}

/**
 * bitonic_merge -  of integers.
 * @array: An ers.
 * @size: The  array.
 * @start: The starting ay to sort.
 * @seq: The size to sort.
 * @flow: The dirrt in.
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow)
{
	size_t e, jumpe = seq / 2;

	if (seq > 1)
	{
		for (e = start; e < start + jumpe; e++)
		{
			if ((flow == UP && array[e] > array[e + jumpe]) ||
			    (flow == DOWN && array[e] < array[i + jumpe]))
				swap_ints(array + e, array + e + jumpe);
		}
		bitonic_merge(array, size, start, jumpe, flow);
		bitonic_merge(array, size, start + jumpe, jumpe, flow);
	}
}

/**
 * bitonic_seq - Convertnic sequence.
 * @array: An arragers.
 * @size: The sirray.
 * @start: The startin sequence.
 * @seq: The size oic sequence.
 * @flow: The directce block in.
 */
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow)
{
	size_t cuter = seq / 2;
	char *stre = (flow == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, stre);
		print_array(array + start, seq);

		bitonic_seq(array, size, start, cuter, UP);
		bitonic_seq(array, size, start + cuter, cuter, DOWN);
		bitonic_merge(array, size, start, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, size, stre);
		print_array(array + start, seq);
	}
}

/**
 * bitonic_sort - Sort an array 
 * @array: Aegers.
 * @size: The si array.
 * Description: Prints t
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_seq(array, size, 0, size, UP);
}
