#include "sort.h"
void swap(int *x, int *y);

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
	pivot = lomuto(A, first, last, size); /* lomuto partitioning scheme */
	quicksrt(A, first, pivot - 1, size);
	quicksrt(A, pivot + 1, last, size);
}

/**
 * lomuto - returns the new index of the pivot after partitioning
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
int lomuto(int A[], int start, int end, size_t size)
{
	int pivot, i, j;

	pivot = A[end]; /* Make the last element your pivot */
	i = start;	/* This will be -1 at the very beginning */

	for (j = start; j < end; j++) /* loop till just before the pivot */
	{
		if (A[j] < pivot)
		{
			if (i < j)
			{
				swap(&A[i++], &A[j]);
				print_array(A, size);
			}
			else
				i++;
		}
	}
	/***
	 * The pivot is at position end
	 * j is at the postion just before the pivot (end-1)
	 * i is at the position of the last element less than pivot's value
	 * So bring pivot to the next of i:
	 * by swaping its position with the one there
	 */
	if (A[i] > pivot)
	{
		swap(&A[i], &A[end]);
		print_array(A, size);
	}

	return (i); /* i is the position of the pivot*/
}

/**
 * swap - swaps two integer pointers
 * @x: first int variable
 * @y: second int variable
 *
 * Return: void
 */
void swap(int *x, int *y)
{
	int tm;

	tm = *x;
	*x = *y;
	*y = tm;
}
