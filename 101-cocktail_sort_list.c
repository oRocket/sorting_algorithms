#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending order
 *                      using the Cocktail shaker sort algorithm.
 * @list: Double pointer to the head of the doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *tmp;

	if (list == NULL || *list == NULL)
		return;

	do {
		swapped = 0;

		/* Traverse the list from left to right */
		for (tmp = *list; tmp->next != NULL; tmp = tmp->next)
		{
			if (tmp->n > tmp->next->n)
			{
				/* Swap nodes */
				if (tmp->prev != NULL)
					tmp->prev->next = tmp->next;
				else
					*list = tmp->next;

				tmp->next->prev = tmp->prev;
				tmp->prev = tmp->next;
				tmp->next = tmp->next->next;

				if (tmp->next != NULL)
					tmp->next->prev = tmp;

				tmp->prev->next = tmp;
				swapped = 1;

				print_list(*list);
			}
		}

		/* If no swapping occurred, the list is sorted */
		if (!swapped)
			break;

		swapped = 0;

		/* Traverse the list from right to left */
		for (; tmp->prev != NULL; tmp = tmp->prev)
		{
			if (tmp->n < tmp->prev->n)
			{
				/* Swap nodes */
				if (tmp->next != NULL)
					tmp->next->prev = tmp->prev;
				tmp->prev->next = tmp->next;
				tmp->next = tmp->prev;
				tmp->prev = tmp->prev->prev;

				if (tmp->prev != NULL)
					tmp->prev->next = tmp;

				tmp->next->prev = tmp;
				swapped = 1;

				print_list(*list);
			}
		}
	} while (swapped);
}
