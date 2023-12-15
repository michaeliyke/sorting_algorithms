#include "sort.h"

/**
 * _writeline - write a string to the stdout followed by newline
 * @str: string to write
 *
 * Return: on successful return 1
 * On error, -1 is returned, and errno is set appropriately.
 */
int _writeline(char *str)
{
	int n = _putstring(str);

	if (n == 1)
		_putchar('\n');
	return (n);
}

/**
 * _is_digits - reports if eachchars of a string is a digit beween 0 and 9
 * @x: input string
 *
 * Return: 1 if true and 0 if false
 */
int _is_digits(char *x)
{
	while (*x != '\0')
	{
		if (_isdigit(*x) == 0)
			return (0);
		++x;
	}
	return (1);
}

/**
 * _isdigit - reports if eachchars of a string is a digit beween 0 and 9
 * @x: input char
 *
 * Return: 1 if true and 0 if false
 */
int _isdigit(char x)
{
	return (x > 47 && x < 58);
}

/**
 * _atoi - convert a string into number
 * returns 0 if str is not numeric
 * @str: string input
 *
 * check null and return 0
 * skip leading white spaces using while and ptr++
 * determine the sign if provided from the frist char
 * initialize result
 * Loop on if digit
 * set digit
 * check if result > INT_MAX / 10 ||
 * (result == IN_MAX / 10 && digit > INT_MAX %10)
 * then return if sign is 1 INT_MAX else INT_MIN
 * result = (result * 10) + digit
 * p++
 * end loop
 * return sign * result
 *
 * Return: integer value on the string
 */
int _atoi(char *str)
{
	int sign, result, digit;

	if (str == NULL || *str == '\0')
		return (0);
	while (_isspace(*str))
		++str;
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		++str;
	}
	else if (*str == '+')
	{
		++str;
	}
	result = 0;
	while (_isdigit(*str))
	{
		digit = *str - '0';
		if (result > INT_MAX / 10 ||
		    (result == INT_MAX / 10 && digit > INT_MAX % 10))
		{
			return (sign == 1 ? INT_MAX : INT_MIN);
		}
		result = ((result * 10) + digit);
		++str;
	}
	return (sign * result);
}

/**
 * _isspace - report if a given char token is a space char
 * @c: char token to check
 *
 * Return: 1 if true and 0 if false
 */
int _isspace(char c)
{
	int i;
	char sp_chars[7] = {'\n', ' ', '\t', '\f', '\r', '\v', '\0'};

	for (i = 0; i < 7; i++)
	{
		if (sp_chars[i] == c)
			return (1);
	}
	return (0);
}
