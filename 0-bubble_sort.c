#include <stdio.h>
#include "sort.h"

/**
 * bubble_sort - program sorts an array of integers in ascending order
 * using the Bubble sort algorithm.
 *
 * @array: array to be printed after implementating a swap operation.
 * @size: size of the array parameter been sorted.
 *
 * Return: Nothing
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j, temp, swapped;

	if (array == NULL || size <= 1)
		return;

	for (i = 0; i < size; i++)
	{
		swapped = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swapped = 1;
				print_array(array, size);
			}

		}

		if (!swapped)
			break;
	}
}
