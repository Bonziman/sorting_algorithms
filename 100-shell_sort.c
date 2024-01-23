#include "sort.h"

/**
 * shell_sort - sorts an array using interval gaps.
 * @array: the array to be sorted.
 * @size: size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t i;
	int tmp, j, increment;
	
	for (increment = size / 2; increment > 0; increment /= 2)
	{
		for (i = increment; i < size; i++)
		{
			tmp = array[i];
			for (j = i; j >= increment; j -= increment)
			{
				if (tmp < array[j - increment])
				{
					array[j] = array[j - increment];
				}
				else
				{
					break;
				}
			}
			array[j] = tmp;
		}
		print_array(array, size);
	}
}
