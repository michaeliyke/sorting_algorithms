#include "sort.h"

/**
 * _print_int - Print an integer to the std output
 * @n: interger to print
 *
 * Return: void
 *
 * convert intiger into a string and print it
 * create buffer of 20 slots
 * init iterator to 0
 * init sign to 1
 * if num is neg, set sign to neg and make num postive
 * use do while loop to generate digits in reverse order as follows
 * do add '0'+ num % 10 to buffer on slot i++
 * set num to num divided by 10
 * while num is greater than 0
 * if sign is neg, include the - sign
 * end with null-terminator
 *
 * Reverse the string using two pointers
 * use i, and j to reverse the string - i is lready at the end of the string
 * reset j to 0
 * using j, loop through the string and print it using putchar
 */
void _print_int(int n)
{
	char buff[20], temp;
	int i = 0, sign = 1, j;

	if (n < 0)
	{
		sign = -1;
		n = -n;
	}
	do {
		buff[i++] = '0' + n % 10;
		n /= 10;
	} while (n > 0);
	if (sign < 0)
		buff[i++] = '-';
	buff[i] = '\0';
	j = 0;
	i--;
	while (i > j)
	{
		temp = buff[j];
		buff[j] = buff[i];
		buff[i] = temp;
		i--;
		j++;
	}
	j = 0;
	while (buff[j] != '\0')
	{
		_putchar(buff[j]);
		j++;
	}
}

/**
 * print_array - prints array of ints
 * @arr: the array to print
 * @size: size of the array
 *
 * Return: void
 */
void print_array(const int arr[], size_t size)
{
	unsigned int i;

	fflush(stdin);
	for (i = 0; i < size; i++)
	{
		if (i + 1 == size)
			_print_int(arr[i]);
		else
		{
			_print_int(arr[i]);
			_putstring(", ");
		}
	}
	_putchar('\n');
}
