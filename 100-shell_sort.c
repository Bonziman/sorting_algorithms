#include "sort.h"

/**
 * shell_sort - sorts an array using interval gaps.
 * @array: the array to be sorted.
 * @size: size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t i, gap, j;
	int tmp;

	for (gap = 1; gap <= size / 3; gap = gap * 3 + 1)
	;
	for (; gap > 0; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			tmp = array[i];
			for (j = i; j >= gap && array[j - gap] > tmp; j -= gap)
			{
				array[j] = array[j - gap];
			}
			array[j] = tmp;
		}
		print_array(array, size);
	}
}
