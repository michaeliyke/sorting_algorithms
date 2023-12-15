#include "sort.h"

/**
 * _strlen - returns length of a string
 * @string: input string whose length is needed
 *
 * Return: length of string
 */
int _strlen(char *string)
{
	char *pointer = string;

	if (string == NULL || *string == '\0')
		return (0);
	while (*string != '\0')
		++string;
	return ((string - pointer));
}

/**
 * _print_ints - prints array of ints
 * @arr: the array to print
 * @size: size of the array
 *
 * Return: void
 */
void _print_ints(int arr[], unsigned int size)
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

/**
 * _strcpy - copies *src, including the \0 char,to dest
 * @dest: the destination of copy operation
 * @src: the source of copy operation
 *
 * Return: pointer to str
 */
char *_strcpy(char *dest, char *src)
{
	int i = _strlen(src);
	char *ptr = dest;

	while (i > 0 && *src != '\0')
	{
		*dest++ = *src++;
		i--;
	}
	*dest++ = '\0';
	return (ptr);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _putstring - write a string to the stdout
 * @str: string to write
 *
 * Return: on successful return 1
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putstring(char *str)
{
	char *p = str;
	int n;

	if (str == NULL)
		return (-1);

	while (*p != '\0')
		n = _putchar(*p++);
	if (n != 1)
		return (n);
	return (1);
}
