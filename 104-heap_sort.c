#include <stdio.h>
#include "sort.h"

/**
 * sift_down - Performs the sift-down operation to maintain the heap property.
 *
 * @array: The array to be sorted
 * @size: Size of the array
 * @start: The root index of the heap
 * @end: The end index of the heap
 */
void sift_down(int *array, size_t size, size_t start, size_t end)
{
	size_t root = start;
	size_t child, swap;

	while (2 * root + 1 <= end)
	{
		child = 2 * root + 1;
		swap = root;

		if (array[swap] < array[child])
			swap = child;

		if (child + 1 <= end && array[swap] < array[child + 1])
			swap = child + 1;

		if (swap != root)
		{
			int temp = array[root];

			array[root] = array[swap];
			array[swap] = temp;

			print_array(array, size);
			root = swap;
		}
		else
			return;
	}
}

/**
 * heapify - Builds a max heap from the given array.
 *
 * @array: The array to be sorted
 * @size: Size of the array
 */
void heapify(int *array, size_t size)
{
	size_t start = (size - 2) / 2;

	while (start + 1 > 0)
	{
		sift_down(array, size, start, size - 1);
		start--;
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order using heap sort.
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void heap_sort(int *array, size_t size)
{
	if (array && size > 1)
	{
		size_t end = size - 1;

		heapify(array, size);

		while (end > 0)
		{
			int temp = array[end];

			array[end] = array[0];
			array[0] = temp;

			print_array(array, size);
			end--;

			sift_down(array, size, 0, end);
		}
	}
}
