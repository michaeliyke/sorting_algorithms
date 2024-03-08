#include "deck.h"

int compare(const void *x_v, const void *y_v)
{
	const int x = *(const int *)x_v;
	const int y = *(const int *)y_v;

	return (x - y);
}

int main(void)
{
	char names[][20] = {} int i;

	qsort(nums, 10, sizeof(int), compare);
	for (i = 0; i < 10; i++)
		printf("%d ", nums[i]);
	putchar('\n');
	return (EXIT_SUCCESS);
}
