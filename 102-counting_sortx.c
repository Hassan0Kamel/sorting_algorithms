#include "sort.h"

/**
 * get_max - Get the integers.
 * @array: An arrategers.
 * @size: The sarray.
 * Return: The maxrray.
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
 * counting_sort - Sort an array of integ
 * @array: An ategers.
 * @size: The size ay.
 * Description: Prints the cosetting it up.
 */
void counting_sort(int *array, size_t size)
{
	int *counte, *sortede, maxe, e;

	if (array == NULL || size < 2)
		return;

	sortede = malloc(sizeof(int) * size);
	if (sortede == NULL)
		return;
	maxe = get_max(array, size);
	counte = malloc(sizeof(int) * (maxe + 1));
	if (counte == NULL)
	{
		free(sortede);
		return;
	}

	for (e = 0; e < (maxe + 1); e++)
		counte[e] = 0;
	for (e = 0; e < (int)size; e++)
		counte[array[e]] += 1;
	for (e = 0; e < (maxe + 1); e++)
		counte[e] += counte[e - 1];
	print_array(counte, maxe + 1);

	for (e = 0; e < (int)size; e++)
	{
		sortede[counte[array[e]] - 1] = array[e];
		counte[array[e]] -= 1;
	}

	for (e = 0; e < (int)size; e++)
		array[e] = sortede[e];

	free(sortede);
	free(counte);
}
