#include "sort.h"

void shell_sort(int A[], size_t n)
{
	int gap, i, j, size;

	size = (int)n;
	/* For each pass of the first loop, gap reduces by half */
	for (gap = size / 2; gap >= 1; gap /= 2)
	{
		/* j steps through n using gap to reduce iter count */
		for (j = gap; j < size; j++)
		{
			/* i makes use of gap to swap values */
			for (i = j - gap; i >= 0; i -= gap)
			{
				if (A[i + gap] > A[i])
					break;
				else
				{
					swap(&A[i + gap], &A[i]);
					_print_ints(A, size);
				}
			}
		}
	}
}
