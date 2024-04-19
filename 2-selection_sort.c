#include "sort.h"

/**
 * selection_sort- sorts an array with selection sort algorithm
 * @array: input array
 * @size: size of array
*/

void selection_sort(int *array, size_t size)
{
	unsigned int i;
	unsigned int j;
	int minimum;
	int swap;
	int save_index;
	int temp;

	if (array == NULL)
	{
		return;
	}

	for (i = 0; i < size - 1; i++)
	{
		minimum = array[i];
		save_index = i;
		swap = 0;
		for (j = i + 1; j < size; j++)
		{
			if (minimum > array[j])
			{
				minimum = array[j];
				swap = 1;
				save_index = j;
			}
		}
		if (swap == 1)
		{
			temp = array[i];
			array[i] = array[save_index];
			array[save_index] = temp;
			print_array(array, size);
		}
	}
}
