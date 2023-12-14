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
	size_t step, jdx;
	int temp, flag;

	if (!array || size < 2)
		return;

	for (step = 0; step < size - 1; step++)
	{
		flag = 0; /* swap checker */
		for (jdx = 0; jdx < size - step - 1; jdx++)
		{
			if (array[jdx] > array[jdx + 1])
			{
				/* swap */
				temp = array[jdx];
				array[jdx] = array[jdx + 1];
				array[jdx + 1] = temp;
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
