#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
/**
 * counting_sort - Sorts an array of integers in ascending order using
 *                 the Counting sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void counting_sort(int *array, size_t size)
{
	int *count, max = array[0];
	size_t i, index;

	if (array == NULL || size < 2)
		return;
	/* Find the maximum value in the array */
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	/* Create and initialize the counting array */
	count = malloc((max + 1) * sizeof(int));
	if (count == NULL)
		return;
	for (i = 0; i <= max; i++)
		count[i] = 0;
	/* Count occurrences of each element in the array */
	for (i = 0; i < size; i++)
		count[array[i]]++;
	/* Print the counting array */
	print_array(count, max + 1);
	/* Update the original array with sorted values */
	index = 0;
	for (i = 0; i <= max; i++)
	{
		while (count[i] > 0)
		{
			array[index] = i;
			index++;
			count[i]--;
		}
	}
	/* Free the counting array */
	free(count);
}
