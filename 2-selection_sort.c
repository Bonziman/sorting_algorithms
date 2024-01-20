#include "sort.h"

/**
 * swap - swaps two integers
 * @xp: first int
 * @yp: second integer
 */
void swap(int *xp, int *yp)
{
	int tmp = *xp;
	*xp = *yp;
	*yp = tmp;
}

/**
 * selection_sort - sorts an array of integers in ascending
 * order using the Selection Sort algorithm
 *
 * @array: the unsorted array to sort
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
				min_idx = j;
		}

		if (min_idx != i)
		{
			swap(&array[min_idx], &array[i]);
			print_array(array, size);
		}
	}
}
