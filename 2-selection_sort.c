#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order using
 * the Selection sort algorithm.
 *
 * @array: the array of integers to be sorted
 * @size: size of the array
 */

void selection_sort(int *array, size_t size)
{
	int *temp;
	size_t i, curr_min_idx, j, aux;

	if (array == NULL || size <= 1)
		return;

	temp = (int*)malloc(sizeof(int) * size);

	if (temp == NULL)
		return;

	for (i = 0; i < size; i++)
		temp[i] = array[i];

	for (i = 0; i < size - 1; i++)
	{
		curr_min_idx = i;

		for (j = i + 1; j < size; j++)
			if (temp[j] < temp[curr_min_idx])
				curr_min_idx = j;

		aux = temp[curr_min_idx];
		temp[curr_min_idx] = temp[i];
		temp[i] = aux;
		print_array(temp, size);
	}
	for (i = 0; i < size; i++)
		array[i] = temp[i];

	free(temp);
}
