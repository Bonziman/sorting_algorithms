#include "sort.h"
#include <stdlib.h>


void quick_sort(int *array, size_t size) {
	if (array == NULL || size < 1)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}

void quick_sort_recursive(int *array, int low, int high, size_t size) {
	if (low < high) {
		int middle = low + (high - low) / 2;
		int pivot = lomuto_partition(array, low, high, size);

		if (array[low] > array[middle])
			swap(&array[low], &array[middle]);
		if (array[middle] > array[high])
			swap(&array[middle], &array[high]);
		if (array[low] > array[middle])
			swap(&array[low], &array[middle]);

		quick_sort_recursive(array, low, pivot - 1, size);
		quick_sort_recursive(array, pivot + 1, high, size);
	}
}

int lomuto_partition(int *array, int low, int high, size_t size) {
	int pivot = array[high];
	int i = low - 1, j;

	for (j = low; j <= high - 1; j++) {
		if (array[j] < pivot) {
			i++;
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
	}

	swap(&array[i + 1], &array[high]);
	print_array(array, size);

	return (i + 1);
}

void swap(int *xp, int *yp) {
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

