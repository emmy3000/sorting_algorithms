#include "sort.h"


/**
 * merge - Merge two sorted sub-arrays into a single sorted array.
 *
 * @array: The array to sort.
 * @left: The leftmost index of the left sub-array.
 * @middle: The index separating the two sub-arrays.
 * @right: The rightmost index of the right sub-array.
 * @copy: A temporary array to hold the merged result.
 *
 * Description: This function assumes that the sub-arrays from left
 * to middle and from middle + 1 to right are already sorted. It
 * merges them into a single sorted array using an auxiliary array
 * to hold the merged result.
 *
 * Return: Nothing
 */

void merge(int *array, size_t left, size_t middle, size_t right, int *copy)
{
	size_t i, j, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + left, middle - left);
	printf("[right]: ");
	print_array(array + middle, right - middle);

	/* Copy both sub-arrays to the auxilliary array */
	for (i = left; i <= right; i++)
		copy[i] = array[i];

	/* Merge two sub-arrays back to original length */
	i = left;
	j = middle + 1;
	k = left;

	while (i <= middle && j <= right)
	{
		if (copy[i] <= copy[j])
			array[k++] = copy[i++];
		else
			array[k++] = copy[j++];
	}

	while (i <= middle)
		array[k++] = copy[i++];

	while (j <= right)
		array[k++] = copy[j++];

	printf("[Done]: ");
	print_array(array + left, right - left + 1);
}


/**
 * merge_sort_recursive - Sort an array recursively
 * using the Merge sort algorithm.
 *
 * @array: The array to sort.
 * @left: The leftmost index of the array to sort.
 * @right: The rightmost index of the array to sort.
 * @copy: A temporary array to hold the sorted sub-arrays.
 *
 * Description: This function recursively divides the array into two
 * halves and sorts them using the merge function.
 *
 * Return: Nothing
 */

void merge_sort_recursive(int *array, size_t left, size_t right, int *copy)
{
	size_t middle;

	if (left < right)
	{
		middle = left + (right - left) / 2;

		merge_sort_recursive(array, left, middle, copy);
		merge_sort_recursive(array, middle + 1, right, copy);

		merge(array, left, middle, right, copy);
	}
}


/**
 * merge_sort - Sort an array of integers in ascending order
 * using the Merge sort algorithm.
 *
 * @array: The array to sort.
 * @size: The size of the array.
 *
 * Description: This function allocates a temporary array to hold
 * the sorted sub-arrays during the recursion, then calls the
 * recursive merge_sort_recursive function to sort the array.
 *
 * Return: Nothing
 */

void merge_sort(int *array, size_t size)
{
	int *copy;

	if (!array || size < 2)
		return;

	copy = malloc(sizeof(int) * size);

	if (!copy)
		return;

	merge_sort_recursive(array, 0, size - 1, copy);

	free(copy);
}
