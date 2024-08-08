#include "sort.h"

/**
 * selection_sort - program recreates the selection sort algorithm
 * @array: is an array of integer
 * @size: is the size of the array
 * Return: void
 */

void selection_sort(int *array, size_t size)
{
	size_t start, index, min_index;
	int tmp;
	
	if (array == NULL)
		return;

	for (start = 0; start < size - 1; start++)
	{
		min_index = start;
		for (index = start + 1; index < size; index++)
		{
			if (array[index] < array[min_index])
			{
				min_index = index;
			}
		}

		if (min_index != start)
		{
			tmp = array[start];
			array[start] = array[min_index];
			array[min_index] = tmp;
		}

		print_array(array, size);
	}
}
