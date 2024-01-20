#include "sort.h"

/**
 * swap - swaps two elements
 * @xp: first element
 * @yp: second element
 * Returns: nothing
 */
void swap(int *xp, int *yp)
{
	int tmp;

	tmp = *xp;
	*xp = *yp;
	*yp = tmp;
}

/**
 * bubble_sort - sorts an array of integers in ascending
 * order using the Bubble sort algorithm
 *
 * @array: the unsorted array to be sorted
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i;
	size_t j;
	int min_idx;

	for (i = 0; i < size; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
				min_idx = j;
		}
	swap(&array[min_idx], &array[i]);
	print_array(array, size);
	}
}
