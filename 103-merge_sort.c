#include "sort.h"

void merge(int *array, int low, int mid, int high)
{
	int *temp = (int *)malloc((high - low + 1) * sizeof(int));
	int i = low;
	int j = mid + 1;
	int k = 0;

	while (i <= mid && j <= high)
	{
		if (array[i] <= array[j])
		{
			temp[k] = array[i];
			i++;
		} else
		{
			temp[k] = array[j];
			j++;
		}
		k++;
	}

	while (i <= mid)
	{
		temp[k] = array[i];
		i++;
		k++;
	}

	while (j <= high)
	{
		temp[k] = array[j];
		j++;
		k++;
	}

	memcpy(array + low, temp + low, (high - low + 1) * sizeof(int));
	free(temp);
}

void merge_sort(int *array, size_t size)
{
	if (size <= 1)
	{
		return;
	}

	int low = 0;
	int high = size - 1;
	int mid = low + (high - low) / 2;

	merge_sort(array, mid);
	merge_sort(array + mid + 1, size - mid - 1);
	merge(array, low, mid, high);
}
