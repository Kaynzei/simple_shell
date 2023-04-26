#include "shell.h"

/**
 * _strlen - A function that returns the length of a string
 * @s: the string
 *
 * Return: length of string
 */
int _strlen(char *s)
{
	int longi = 0;

	if (!s)
		return (0);

	while (*s++)
		longi++;
	return (longi);
}

/**
 * _strcmp - A function that compares two strings
 * @s1: the first input value
 * @s2: the second input value
 *
 * Return: 0 if s1 == s2, 1 if s1 > s2 & -1 if s1 < s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - A function that checks if needle starts with haystack
 * @haystack: string to search
 * @needle: the substring to find
 *
 * Return: address of next char of haystack or NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - A function that concatenates two strings
 * @dest: the destination buffer
 * @src: the source buffer
 *
 * Return: pointer to dest
 */
char *_strcat(char *dest, char *src)
{
	char *x = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (x);
}
