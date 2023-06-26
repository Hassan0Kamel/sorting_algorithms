#include "sort.h"

int get_max(int *array, int size);
void radix_counting_sort(int *array, size_t size, int sig, int *buff);
void radix_sort(int *array, size_t size);

/**
 * get_max - Get t array of integers.
 * @array: An arers.
 * @size: The s array.
 * Return: The maximum the array.
 */
int get_max(int *array, int size)
{
	int maxe, e;

	for (maxe = array[0], e = 1; e < size; e++)
	{
		if (array[e] > maxe)
			maxe = array[e];
	}

	return (maxe);
}

/**
 * radix_counting_sort - Sort the signi
 * @array: An ars.
 * @size: The sizy.
 * @sig: The sign sort on.
 * @buff: A buffer rted array.
 */
void radix_counting_sort(int *array, size_t size, int sig, int *buff)
{
	int counter[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t e;

	for (e = 0; e < size; e++)
		counter[(array[e] / sig) % 10] += 1;

	for (e = 0; e < 10; e++)
		counter[e] += counter[e - 1];

	for (e = size - 1; (int)e >= 0; e--)
	{
		buff[counter[(array[e] / sig) % 10] - 1] = array[e];
		counter[(array[e] / sig) % 10] -= 1;
	}

	for (e = 0; e < size; e++)
		array[e] = buff[e];
}

/**
 * radix_sort - Sort an array 
 * @array: An arragers.
 * @size: The sirray.
 * Description: Implements the LSD radix so
 */
void radix_sort(int *array, size_t size)
{
	int maxe, sige, *buffe;

	if (array == NULL || size < 2)
		return;

	buffe = malloc(sizeof(int) * size);
	if (buffe == NULL)
		return;

	maxe = get_max(array, size);
	for (sige = 1; maxe / sige > 0; sige *= 10)
	{
		radix_counting_sort(array, size, sige, buffe);
		print_array(array, size);
	}

	free(buffe);
}
