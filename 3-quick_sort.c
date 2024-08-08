#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order
 *              using the Quick sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_rec(array, 0, size - 1, size);
}

/**
 * quick_sort_rec - Recursive function to perform Quick sort
 * @array: array to be sorted
 * @low: leftmost index of the subarray
 * @high: rightmost index of the subarray
 * @size: full size of the array
 */
void quick_sort_rec(int *array, int low, int high, size_t size)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = partition(array, low, high, size);
		quick_sort_rec(array, low, pivot_index - 1, size);
		quick_sort_rec(array, pivot_index + 1, high, size);
	}
}

/**
 * partition - Partitions the array using the Lomuto partition scheme
 * @array: The array to be partitioned
 * @left: The leftmost index of the subarray
 * @right: The rightmost index of the subarray
 * @size: The full size of the array
 *
 * Return: The index of the pivot after partitioning.
 */

int partition(int *array, int left, int right, size_t size)
{
	int start_1, start_2, pivot, temp;

	pivot = array[right];
	start_1 = left;

	for (start_2 = left; start_2 < right; start_2++)
	{
		if (array[start_2] < pivot)
		{
			if (start_1 != start_2)
			{
				temp = array[start_2];
				array[start_2] = array[start_1];
				array[start_1] = temp;
				print_array(array, size);
			}
			start_1++;
		}
	}
	if (array[start_1] != array[right])
	{
		temp = array[start_1];
		array[start_1] = array[right];
		array[right] = temp;
		print_array(array, size);
	}

	return (start_1);
}
