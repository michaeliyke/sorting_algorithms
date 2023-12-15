#include "sort.h"

/**
 * selection_sort - sort integer values using selection the sort algorithm
 * Starts with the leftmost value as x, compares with the rest of the values.
 * Update x if a less value is found from left to right.
 * Then swap the positions of x and the current index.
 * Repeat as index moves from left to right.
 *
 * @nums: an array of integers
 * @len: the length of the array
 *
 * Return: void
 */
void selection_sort(int *nums, size_t len)
{
	int temp;
	unsigned int i, rightmost, leftmost;

	for (i = 0; i < len; i++)
	{
		leftmost = i; /* save the leftmost position */
		for (rightmost = i; rightmost < len; rightmost++)
			if (nums[rightmost] < nums[leftmost])
				leftmost = rightmost;
		/* leftmost now probably holds the position of a less value*/
		if (leftmost != i)
		{ /* swap the values using a temporary variable */
			temp = nums[leftmost];
			nums[leftmost] = nums[i];
			nums[i] = temp;
			_print_ints(nums, len);
		}
	}
}
