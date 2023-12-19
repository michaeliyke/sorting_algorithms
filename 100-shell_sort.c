#include "sort.h"
void swap(int *x, int *y);

/**
 * shell_sort - shell sort implementation using the knuth sequence
 * Also known as increments sequence
 * @a: array to be sorted
 * @size: array size
 *
 * Return: void
 */
void shell_sort(int a[], size_t size)
{
	int gap, i, j;

	if (a == NULL || size < 2)
		return;

	/**
	 * Initial calculation of gap using Knuth sequence
	 * Also known as increments sequence
	 */
	for (gap = 1; gap <= (int)size / 3; gap = 3 * gap + 1)
		;

	/* For each pass of the first loop, gap reduces by half */
	for (; gap >= 1; gap /= 3)
	{
		/* j steps through n using gap to reduce iter count */
		for (j = gap; j < (int)size; j++)
			/* i makes use of gap to swap values */
			for (i = j - gap; i >= 0; i -= gap)
			{
				if (a[i + gap] >= a[i])
					break; /* >= makes it a stable sort */
				swap(&a[i + gap], &a[i]);
				print_array(a, size);
			}
	}
}

/**
 * shell_sort_gap_rdctn - shell sort with the gap reduction algorithm
 * @A: the array to sort
 * @n: array size
 *
 * Return: void
 */
void shell_sort_gap_rdctn(int A[], size_t n)
{
	int gap, i, j, size;

	size = (int)n;

	/**
	 * Initial calculation of gap using the Gap Reduction technique
	 * There are other techniques as well such as the Knuth sequence
	 * demonstrated above
	 */
	gap = size / 2;

	/* For each pass of the first loop, gap reduces by half */
	for (; gap >= 1; gap /= 2)
	{
		/* j steps through n using gap to reduce iter count */
		for (j = gap; j < size; j++)
		{
			/* i makes use of gap to swap values */
			for (i = j - gap; i >= 0; i -= gap)
			{
				if (A[i + gap] > A[i])
					break;
				swap(&A[i + gap], &A[i]);
				print_array(A, size);
			}
		}
	}
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
