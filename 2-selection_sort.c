#include "sort.h"

/**
 * swap - Swaps the values of two integers.
 *
 * @a: integer pointer to first value to be swapped
 * @b: integer pointer to second value to be swapped
 *
 * Return: Nothing
 */

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * selection_sort - Sorts an array of integers in ascending order using
 * the Selection sort algorithm.
 *
 * @array: the array of integers to be sorted
 * @size: size of the array
 *
 * Return: Nothing
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, curr_min_idx;

	if (array == NULL || size <= 1)
		return;

	for (i = 0; i < size; i++)
	{
		curr_min_idx = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[curr_min_idx])
				curr_min_idx = j;
		}

		if (curr_min_idx != i)
		{
			swap(&array[curr_min_idx], &array[i]);
			print_array(array, size);
		}
	}
}
