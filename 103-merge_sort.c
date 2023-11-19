#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * merge - Merges two subarrays of arr[].
 *
 * @arr: The array to be sorted
 * @left: Starting index of the left subarray
 * @mid: Middle index of the array
 * @right: Ending index of the right subarray
 */
void merge(int *arr, int left, int mid, int right)
{
	int i, j, k;
	int n1 = mid - left + 1;
	int n2 = right - mid;

	int *L = malloc(sizeof(int) * n1);
	int *R = malloc(sizeof(int) * n2);

	if (!L || !R)
	{
		free(L);
		free(R);
		return;
	}

	for (i = 0; i < n1; i++)
		L[i] = arr[left + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[mid + 1 + j];

	i = 0;
	j = 0;
	k = left;

	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}

	free(L);
	free(R);
}

/**
 * merge_sort_recursive - Main function for recursive merge sort
 *
 * @array: The array to be sorted
 * @left: Starting index of the array
 * @right: Ending index of the array
 */
void merge_sort_recursive(int *array, int left, int right)
{
	int mid;

	if (left < right)
	{
		mid = left + (right - left) / 2;

		merge_sort_recursive(array, left, mid);
		merge_sort_recursive(array, mid + 1, right);

		printf("Merging...\n");
		printf("[left]: ");
		print_array(array + left, mid - left + 1);
		printf("[right]: ");
		print_array(array + mid + 1, right - mid);
		merge(array, left, mid, right);
		printf("[Done]: ");
		print_array(array + left, right - left + 1);
	}
}

/**
 * merge_sort - Sorts an array of integers in ascending order using merge sort
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void merge_sort(int *array, size_t size)
{
	if (array && size > 1)
	{
		merge_sort_recursive(array, 0, size - 1);
	}
}
