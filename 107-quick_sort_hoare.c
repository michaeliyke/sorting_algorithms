#include "sort.h"

/**
 * quick_sort_hoare - base of quicksort_fn_hoare
 *
 * @array: array of numbers
 * @size: siz of th array
 *
 * Return: void
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort_fn_hoare(array, 0, size - 1, size);
}

/**
 * quicksort_fn_hoare - quick sort algorithm
 *
 * @A: array of numbers
 * @size: siz of th array
 * @low: the first index
 * @high: the last index
 *
 * Return: void
 */
void quicksort_fn_hoare(int A[], int low, int high, size_t size)
{
	int partitionIndex;

	if (high > low)
	{
		partitionIndex = hoare_rt_pvt(A, low, high, size);
		quicksort_fn_hoare(A, low, partitionIndex - 1, size);
		quicksort_fn_hoare(A, partitionIndex, high, size);
	}
}

/**
 * hoare_rt_pvt - the hoare partitioning scheme for quick sort
 * @A: array of integers
 * @left: partition start index
 * @right: partition last index
 * @size: size of the array
 *
 * Return: the
 */
int hoare_rt_pvt(int A[], int left, int right, size_t size)
{
	int pivot, i, j;

	pivot = A[right]; /* The last element */
	i = left - 1;
	j = right + 1;
	while (i < j)
	{
		/* move i right till it A[i] is >= pivot if at all  */
		while (A[++i] < pivot)
			;
		/* move j left till it A[j] is <= pivot if at all  */
		while (A[--j] > pivot)
			;
		/**
		 * Have i and j crossed? Then the A partition is complete
		 * We return j because it is the rightmost index of the left
		 * partition i.e before pivot.
		 * The position of the pivot may or may not be the j + 1
		 * and so makes that unreliable. This also makes the position
		 * of i unreliable as well.
		 */

		/**
		 * A[i] and A[j] are on the wrong sides of the pivot
		 * swap them
		 */
		if (i <= j)
		{
			swap(&A[i], &A[j]);
			print_array(A, size);
		}
	}
	return (i);
}

/**
 * hoare_lf_pvt - the hoare partitioning scheme for quick sort
 * @A: array of integers
 * @left: partition start index
 * @right: partition last index
 * @size: size of the array
 *
 * Return: the
 */
int hoare_lf_pvt(int A[], int left, int right, size_t size)
{
	int pivot, i, j;

	pivot = A[left]; /* The last element */
	i = left - 1;
	j = right + 1;
	while (1)
	{
		/* move i right till it A[i] is >= pivot if at all  */
		while (A[++i] < pivot)
			;
		/* move j left till it A[j] is <= pivot if at all  */
		while (A[--j] > pivot)
			;
		/**
		 * Have i and j crossed? Then the A partition is complete
		 * We return j because it is the rightmost index of the left
		 * partition i.e before pivot.
		 * The position of the pivot may or may not be the j + 1
		 * and so makes that unreliable. This also makes the position
		 * of i unreliable as well.
		 */
		if (i >= j)
			return (j);
		/**
		 * A[i] and A[j] are on the wrong sides of the pivot
		 * swap them
		 */
		print_array(A, size);
		swap(&A[i], &A[j]);
	}
}
