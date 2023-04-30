#include "sort.h"


/**
 * swap_ints - Swap two integers in an array.
 *
 * @a: Pointer to the first integer
 * @b: Pointer to thesecond integer
 *
 * Return: Nothing
 */
void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * heapify_down - Move a node down the tree until it
 * satisfies the max heap
 *
 * @array: An arrya of integers representing a binary
 * @size: The size of the array/tree
 * @root: The index of the root node of the subtree to heapify.
 */
void heapify_down(int *array, size_t size, size_t root)
{
	size_t largest = root;
	size_t left = 2 * root + 1;
	size_t right = 2 * root + 2;

	if (left < size && array[left] > array[largest])
		largest = left;

	if (right < size && array[right] > array[largest])
		largest = right;

	if (largest != root)
	{
		swap_ints(&array[root], &array[largest]);
		print_array(array, size);
		heapify_down(array, size, largest);
	}
}


/**
 * heap_sort - Sort an array of integers in ascending order
 * using the heap sort algorithm.
 *
 * @array: Poniters to an array of integers.
 * @size: Size of the array.
 *
 */
void heap_sort(int *array, size_t size)
{
	int i;
	int temp;

	for (i = (int)size / 2 - 1; i >= 0; i--)
		heapify_down(array, size, i);

	for (i = size - 1; i > 0; i--)
	{
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		print_array(array, size);
		heapify_down(array, i, 0);
	}
}
