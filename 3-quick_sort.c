#include "sort.h"

/**
 * partitioner- uses the lomuto partition scheme
 * @array: input array
 * @lower: lower bound
 * @upper: upper bound
 * @size: array size
 *
 * Returns: next partition
*/

int partitioner(int *array, int lower, int upper, int size)
{
	int pivot;
	int i;
	int j;
	int temp;

	pivot = array[upper];
	i = lower;

	for (j = lower; j < upper; j++)
	{
		if (array[j] <= pivot)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			if (temp != array[i])
			{
				print_array(array, size);
			}
			i++;
		}
	}

	temp = array[i];
	array[i] = array[j];
	array[j] = temp;
	if (temp != array[i])
	{
		print_array(array, size);
	}
	return (i);
}

/**
 * quick_sort_help- helps the quick_sort function recursively
 * @array: input array
 * @lower: lower bound
 * @upper: upper bound
 * @size: size of array
*/

void quick_sort_help(int *array, int lower, int upper, int size)
{
	int pivot;

	pivot = 0;

	if (lower < upper)
	{
		pivot = partitioner(array, lower, upper, size);

		quick_sort_help(array, lower, pivot - 1, size);
		quick_sort_help(array, pivot + 1, upper, size);
	}
}

/**
 * quick_sort- sorts an array with the quick sort algoritm
 * @array: input array
 * @size: size of array
*/

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
	{
		return;
	}

	quick_sort_help(array, 0, size - 1, size);
}
