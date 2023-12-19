#include "sort.h"

/**
 * merge_sort - the merge sort algorithm's interface
 * @array: array of integers to be sorted
 * @size: size of the array
 *
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	mergesrt(array, 0, size - 1);
}

/**
 * mergesrt - the merge sort algorithm implementation
 * @A: array of integers to be sorted
 * @left: the start of the array at current state,
 * the position of the first element itself
 * @right: the end of the array at current state,
 * the position of the last element itself
 *
 * Return: void
 */
void mergesrt(int A[], int left, int right)
{
	int mid;

	if (right <= left)
		return;
	mid = (right + left) / 2;
	/* above avoids integer overflow for large integers */
	mergesrt(A, left, mid);
	mergesrt(A, mid + 1, right);
	merge(A, left, mid, right);
}

/**
 * merge - the merger function for mergesrt
 * @A: array of integers to be sorted
 * @left: the start of the array at current state,
 * the position of the first element itself
 * @right: the end of the array at current state,
 * the position of the last element itself
 * @mid: the middle of the current array,
 * size of the left array is less than or equal to that of the right array
 *
 * Return: void
 */
void merge(int A[], int left, int mid, int right)
{
	int *temp; /* temporaray array for staging */

	int i; /* counter for - left array*/
	int j; /* counter for - right array*/
	int k; /* counter for temp array */
	int *left_data = array_from_boundary(A, left, mid);
	int *right_data = array_from_boundary(A, mid + 1, right);

	k = i = left;
	j = mid + 1;
	temp = malloc(sizeof(int) * (left + right + 1));

	printf("Merging...\n[left]: ");
	print_array(left_data, mid - left + 1);
	printf("[right]: ");
	print_array(right_data, right - mid);
	/* copy from both left and rigth arrays but in a sorted manner */
	while (i <= mid && j <= right)
	{
		if (A[i] < A[j])
			temp[k++] = A[i++];
		else
			temp[k++] = A[j++];
	}

	/* copy left-overs of left array if any */
	while (i <= mid)
		temp[k++] = A[i++];

	/* copy left-overs of right array if any */
	while (j <= right)
		temp[k++] = A[j++];

	/* move sorted data from the staging area to the main array */
	for (k = left; k <= right; k++)
		A[k] = temp[k];
	free(temp);
	printf("[Done]: ");
	print_array(A, right - left + 1);
}

/**
 * array_from_boundary - returns a new array from a given boundary
 *  of another array
 * @A: the original array
 * @left: left boundry inclusive
 * @end: right boundary inclusive
 *
 * Return: a new array
 */
int *array_from_boundary(int A[], int left, int end)
{
	int i, j;
	int *new = malloc(sizeof(int) * (end - left + 1));

	for (i = left, j = 0; i <= end; i++)
		new[j++] = A[i];

	return (new); /* malloc'd and should be free'd*/
}
