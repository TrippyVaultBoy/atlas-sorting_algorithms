#include "sort.h"

/**
 *
*/

int partitioner(int *array, int lower, int upper)
{
	int pivot;
	int i;
	int j;
	int temp;

	pivot = array[upper];
	i = lower - 1;

	for (j = lower; j < upper; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
	}

	temp = array[i + 1];
	array[i + 1] = array[upper];
	array[upper] = temp;

	return (i + 1);
}

/**
 *
*/

void quick_sort_help(int *array, int lower, int upper, int size)
{
	int pivot;

	if (lower < upper)
	{
		pivot = partitioner(array, lower, upper);

		quick_sort_help(array, lower, pivot - 1, size);
		print_array(array, size);
		quick_sort_help(array, pivot + 1, upper, size);
		print_array(array, size);
	}
}

/**
 *
*/

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
	{
		return;
	}

	quick_sort_help(array, 0, size - 1, size);
}