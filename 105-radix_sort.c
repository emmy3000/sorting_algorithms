#include "sort.h"
/**
 * radix_sort - sorts an array of integers in ascending order
 * using the LSD radix sort algorithm.
 * @array: pointer to the array to sort
 * @size: size of the array to sort
 */
void radix_sort(int *array, size_t size)
{
	int i, max = 0, exp = 1;
	int *bucket = NULL, *output = NULL;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < (int)size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	bucket = malloc(sizeof(int) * 10);
	output = malloc(sizeof(int) * size);
	if (bucket == NULL || output == NULL)
	{
		free(bucket);
		free(output);
		return;
	}
	while (max / exp > 0)
	{
		for (i = 0; i < 10; i++)
			bucket[i] = 0;
		for (i = 0; i < (int)size; i++)
			bucket[(array[i] / exp) % 10]++;
		for (i = 1; i < 10; i++)
			bucket[i] += bucket[i - 1];
		for (i = size - 1; i >= 0; i--)
		{
			output[bucket[(array[i] / exp) % 10] - 1] = array[i];
			bucket[(array[i] / exp) % 10]--;
		}
		for (i = 0; i < (int)size; i++)
			array[i] = output[i];

		print_array(array, size);
		exp *= 10;
	}
	free(bucket);
	free(output);
}
