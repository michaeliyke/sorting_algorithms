#include "sort.h"

/**
 * heapify - uses the sift-down approach to build a max heap of the structure.
 * This max heap building involves restoring the heap property of the
 * structure.
 */
void heapify(int a[], int n, int i)
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

void heap_sort(int a[], size_t n)
{
	int i;

	if (a == NULL || n < 2)
		return;

	/**
	 * n / 2 is the location of the last non-leaf element
	 *
	 */
	for (i = n / 2 - 1; i >= 0; i--)
		heapify(a, n, i); /* Build the correct maxheap structure */

	for (i = n - 1; i >= 1; i--)
	{
		swap(&a[0], &a[i]);
		print_array(a, n);
		heapify(a, i, 0);
	}
}
