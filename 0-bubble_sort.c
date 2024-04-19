#include "sort.h"

/**
 *
*/

void bubble_sort(int *array, size_t size)
{
	int swap;
	int array_size;
	int i;
	int temp;

	array_size = size;
	temp = 0;

    if (array == NULL)
    {
        return;
    }

	do
	{
		swap = 0;
		for (i = 0; i < array_size - 1; i++)
    	{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				swap = 1;
			}
		}
		array_size--;
	} while (swap == 1);
}