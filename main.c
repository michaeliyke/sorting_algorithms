#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
	size_t n = sizeof(array) / sizeof(array[0]);

	print_array(array, n);
	printf("\n");
	heap_sort(array, n);
	printf("\n");
	print_array(array, n);
	return (0);
}

void heap_sort_(int a[], size_t n)
{
	int i;

	/* Build max heap */
	for (i = n / 2 - 1; i >= 0; i--)
		heapify(a, n, i);

	/* Extract elements from the heap one by one */
	for (i = n - 1; i > 0; i--)
	{
		swap(&a[0], &a[i]);
		heapify(a, i, 0); /* Adjust the size of the heap */
	}
}

void heapify_(int a[], int n, int i)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && a[left] > a[largest]) /* sh'd be an if instead */
		largest = left;
	if (right < n && a[right] > a[largest]) /* sh'd be an if instead */
		largest = right;
	if (largest != i)
	{
		swap(&a[i], &a[largest]);
		heapify(a, n, largest);
	}
}
