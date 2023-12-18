#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int array[] = {99, 88, 77, 66, 55, 44, 33, 22, 11, 0};
	size_t n = sizeof(array) / sizeof(array[0]);

	print_array(array, n);
	printf("\n");
	quick_sort_hoare(array, n);
	printf("\n");
	print_array(array, n);
	return (0);
}
