#include "shell.h"

/**
 * _erratoi - a function that changes  a string to an integer
 * @s:  string
 * Return: 0 or -1
 */
int _erratoi(char *s)
{
	int r = 0;
	unsigned long int result = 0;

	if (*s == '+')
		s++;
	for (r = 0;  s[r] != '\0'; r++)
	{
		if (s[r] >= '0' && s[r] <= '9')
		{
			result *= 10;
			result += (s[r] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 * print_error - a function that  prints  error
 * @info: parameter info struct
 * @estr: string
 * Return: 0 if no n0s in string, otherwise -1
 */
void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * print_d - a function prints a decimal (integer) number (base 10)
 * @input: the input
 * @fd: the filedescriptor to write to
 *
 * Return: number of characters printed
 */
int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int r, count = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (r = 1000000000; r > 1; r /= 10)
	{
		if (_abs_ / r)
		{
			__putchar('0' + current / r);
			count++;
		}
		current %= r;
	}
	__putchar('0' + current);
	count++;

	return (count);
}

/**
 * convert_number - a function that converts and clone
 * @num: number
 * @base: base
 * @flags: argument flags
 *
 * Return: string
 */
char *convert_number(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * remove_comments - a function that replaces first instance of '#' with '\0'
 * @buf: address of the string to modify
 *
 * Return: Always 0;
 */
void remove_comments(char *buf)
{
	int r;

	for (r = 0; buf[r] != '\0'; r++)
		if (buf[r] == '#' && (!r || buf[r - 1] == ' '))
		{
			buf[r] = '\0';
			break;
		}
}

