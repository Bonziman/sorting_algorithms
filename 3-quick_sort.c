#include "sort.h"
/**
 * quick_sort - sorts an array of integers in ascending
 * order using the Quick sort algorithm (Lomuto partition scheme)
 *
 * @array: the unsorted array to be sorted
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}

/**
 * quick_sort_recursive - Recursive helper function for quick_sort
 *
 * @array: the unsorted array to be sorted
 * @low: the low index of the partition
 * @high: the high index of the partition
 * @size: size of the array
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot = lomuto_partition(array, low, high, size);

		quick_sort_recursive(array, low, pivot - 1, size);
		quick_sort_recursive(array, pivot + 1, high, size);
	}
}

/**
 * lomuto_partition - Lomuto partition scheme for Quick Sort
 *
 * @array: the unsorted array to be partitioned
 * @low: the low index of the partition
 * @high: the high index of the partition
 * @size: size of the array
 *
 * Return: the final index of the pivot element
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1, j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
	}

	swap(&array[i + 1], &array[high]);
	print_array(array, size);

	return (i + 1);
}

/**
 * swap - swaps two elements
 * @xp: first element
 * @yp: second element
 */
void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}
