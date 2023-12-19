#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void heapify_(int a[], int n, int i);

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int array[] = {42, 15, 7, 30, 21, 2, 19, 5, 12, 35};
	size_t n = sizeof(array) / sizeof(array[0]);

	print_array(array, n);
	printf("\n");
	heap_sort(array, n);
	printf("\n");
	print_array(array, n);
	return (0);
}
