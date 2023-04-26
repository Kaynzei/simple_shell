#include "shell.h"

/**
 * _strcpy - A function that copies a string
 * @dest: the destination buffer
 * @src: the source buffer
 *
 * Return: pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int a = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[a])
	{
		dest[a] = src[a];
		a++;
	}
	dest[a] = 0;
	return (dest);
}

/**
 * _strdup - A function that duplicates a string
 * @str: the string to be duplicated
 *
 * Return: pointer to the duplicated string
 */
char *_strdup(const char *str)
{
	int longi = 0;
	char *x;

	if (str == NULL)
		return (NULL);
	while (*str++)
		longi++;
	x = malloc(sizeof(char) * (longi + 1));
	if (!x)
		return (NULL);
	for (longi++; longi--;)
		x[longi] = *--str;
	return (x);
}

/**
 * _puts - A function that prints a string to stdout
 * @str: the string to be printed
 *
 * Return: void
 */
void _puts(char *str)
{
	int a = 0;

	if (!str)
		return;
	while (str[a] != '\0')
	{
		_putchar(str[a]);
		a++;
	}
}

/**
 * _putchar - A function that writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and error is set appropriately.
 */
int _putchar(char c)
{
	static int a;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || a >= WRITE_BUF_SIZE)
	{
		write(1, buf, a);
		a = 0;
	}
	if (c != BUF_FLUSH)
		buf[a++] = c;
	return (1);
}
