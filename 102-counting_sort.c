#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order using
 *                 the Counting sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 *
 * Return: void.
 */
void counting_sort(int *array, size_t size)
{
	size_t idx, max_val = 0;
	int *count, *temp;

	if (array == NULL || size == 0)
		return;

	for (idx = 0; idx < size; idx++) /* find highest value */
	{
		if ((size_t)array[idx] > max_val)
			max_val = array[idx];
	}

	count = malloc(sizeof(int) * (max_val + 1));
	temp = malloc(sizeof(int) * size);
	if (count == NULL || temp == NULL)
		return;

	for (idx = 0; idx < max_val + 1; idx++) /* initialize array to 0 */
		count[idx] = 0;

	for (idx = 0; idx < size; idx++) /* update counting array */
		count[array[idx]]++;

	for (idx = 1; idx <= max_val; idx++) /* update counting array */
		count[idx] += count[idx - 1];

	print_array(count, (max_val + 1));
	for (idx = 0; idx < size; idx++) /* store sorted array temporarily */
	{
		temp[count[array[idx]] - 1] = array[idx];
		count[array[idx]]--;
	}

	for (idx = 0; idx < size; idx++)
	{
		array[idx] = temp[idx]; /* reconstruct sorted array */
	}

	free(count);
	free(temp);
}
