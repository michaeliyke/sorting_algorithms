#include "sort.h"

/**
 * quick_sort - aliase to quicksrt
 *
 * @array: array of numbers
 * @size: siz of th array
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksrt(array, 0, size - 1, size);
}

/**
 * quicksrt - quick sort algorithm
 *
 * @A: array of numbers
 * @size: siz of th array
 * @first: the first index
 * @last: the last index
 *
 * Return: void
 */
void quicksrt(int A[], int first, int last, size_t size)
{
	int pivot;

	if (last <= first)
		return;
	pivot = partition(A, first, last, size);
	quicksrt(A, first, pivot - 1, size);
	quicksrt(A, pivot + 1, last, size);
}

/**
 * partition - returns the new index of the pivot after partitioning
 * Partition means sorting A around the value of pivot. The sorting involves,
 * moving all elements less than the value of pivot to the left of it
 * and all elements greater or equal to the right of it.
 * Array is sorted in place
 * @A: array to patition
 * @start: the start index of the A
 * @end: the end index of the A
 * @size: the size of the array for printing
 *
 * Return: the new ondex of pivot
 */
int partition(int A[], int start, int end, size_t size)
{
	int pivot, i, j;

	pivot = A[end]; /* Make the last element your pivot */
	i = start - 1;	/* This will be -1 at the very beginning */

	for (j = start; j <= end - 1; j++) /* loop till just before the pivot */
	{
		if (A[j] < pivot)
		{
			i += 1;
			swap(&A[i], &A[j]);
		}
	}

	/***
	 * The pivot is at position end
	 * j is at the postion just before the pivot (end-1)
	 * i is at the position of the last element less than pivot's value
	 * So bring pivot to the next of i:
	 * by swaping its position with the one there
	 */
	i += 1;
	swap(&A[i], &A[end]);
	_print_ints(A, size);
	return (i); /* i is the position of the pivot*/
}
