#include "sort.h"

/**
 * swap - Swaps the values of two integers.
 *
 * @lf_idx: integer index position swapped with rt_idx's
 * @rt_idx: integer index position swapped with lf_idx's
 *
 * Return: Nothing
 */

void swap(int *lf_idx, int *rt_idx)
{
	int temp = *lf_idx;
	*lf_idx = *rt_idx;
	*rt_idx = temp;
}

/**
 * lomuto_partition - Partitions an array using Lomuto permutation.
 *
 * @array: original array partitioned to obtain pivot position value
 * @low: starting index of the partition
 * @high: ending index of the partition
 * @size: size of the array
 *
 * Return: index position position of the pivot element after been placed
 * in its sorted position
 */

size_t lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			if (i != j)
				print_array(array, size);
		}
	}

	if (array[high] < array[i + 1])
	{
		swap(&array[i + 1], &array[high]);

		if ((i + 1) != high)
			print_array(array, size);
	}

	return (i + 1);
}

/**
 * qs_helper - Recursively sorts an array of integers in ascending
 * order using the Quick sort algorithm and the Lomuto partition scheme
 *
 * @array: array to be sorted
 * @low: starting index of the part the partition
 * @high: ending index of the partition
 * @size: size of the array
 *
 * Return: Nothing
 */

void qs_helper(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		size_t p = lomuto_partition(array, low, high, size);

		qs_helper(array, low, p - 1, size);
		qs_helper(array, p + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using
 * the Quick sort algorithm.
 *
 * @array: array being sorted
 * @size: of array being sorted
 *
 * Return: Nothing
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;

	qs_helper(array, 0, size - 1, size);
}
