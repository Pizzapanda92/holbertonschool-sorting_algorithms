#include"sort.h"

/**
 * bubble_sort - function sorts an array and prints after each swaps
 * @array: is the pointer to the array
 * @size: is the size of the array
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
	int temp;
	size_t outer, inner;

	for (outer = 0; outer < size - 1; outer++)
	{
		for (inner = 0; inner < (size - 1 - outer); inner++)
		{
			if (array[inner] > array[inner + 1])
			{
				/*Swap the elements*/
				temp = array[inner];
				array[inner] = array[inner + 1];
				array[inner + 1] = temp;
				print_array(array, size);
			}
		}
	}
}

