#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order,
 *               using the Bubble sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 *
 * Return: void.
 */
void bubble_sort(int *array, size_t size)
{
	size_t step, idx;
	int temp, flag;

	if (!array || size < 2)
		return;

	for (step = 0; step < size - 1; step++)
	{
		flag = 0; /* swap checker */
		for (idx = 0; idx < size - step - 1; idx++)
		{
			if (array[idx] > array[idx + 1])
			{
				/* swap */
				temp = array[idx];
				array[idx] = array[idx + 1];
				array[idx + 1] = temp;
				flag = 1; /* update flag */
				print_array(array, size);
			}
		}
		if (flag == 0)
		{
			/* if no swap */
			break;
		}
	}
}
