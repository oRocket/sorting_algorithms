#include "sort.h"
#include <stdio.h>

/**
 * shell_sort - Sorts an array of integers in ascending order using
 *              the Shell sort algorithm with the Knuth sequence.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1;
	int temp, i, j;

	if (array == NULL || size < 2)
		return;

	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (i = gap; i < (int)size; i++)
		{
			temp = array[i];

			for (j = i; j >= (int)gap && array[j - gap] > temp; j -= gap)
			{
				array[j] = array[j - gap];
			}

			array[j] = temp;
		}

		print_array(array, size);
		gap /= 3;
	}
}
