#ifndef SORT_H
#define SORT_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;

void lomuto_qsort(int *array, int low, int high, size_t size);
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
listint_t *create_listint(const int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void quicksort_recursive(int *array, int low, int high, size_t size);
int lomuto_partition(int *array, int low, int high, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back);
void merge_subarr(int *subarr, int *buff, size_t front, size_t mid, size_t back);
void merge(int *arr, int left, int mid, int right);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_merge(int *array, size_t low, size_t count, int dir);
void bitonic_sort_recursive(int *array, size_t low, size_t count, int dir);
void bitonic_sort(int *array, size_t size);
void swap(int *i, int *j);
int partition(int *array, int low, int high, size_t size);
void hoare_qsort(int *array, int low, int high, size_t size);
void quick_sort_hoare(int *array, size_t size);


#endif /* sort.h */
