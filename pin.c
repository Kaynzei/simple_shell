#include "shell.h"

/**
 * **strtow - A function that splits a string into words
 * Repeated delimiters are ignored
 * @str: the string to be inputted
 * @d: the delimeter string
 * Return: pointer to an array of strings s if successful
 * NULL if unsuccessful
 */

char **strtow(char *str, char *d)
{
	int a, b, h, i, wordsnum = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (a = 0; str[a] != '\0'; a++)
		if (!is_delim(str[a], d) && (is_delim(str[a + 1], d) || !str[a + 1]))
			wordsnum++;

	if (wordsnum == 0)
		return (NULL);
	s = malloc((1 + wordsnum) * sizeof(char *));
	if (!s)
		return (NULL);
	for (a = 0, b = 0; b < wordsnum; b++)
	{
		while (is_delim(str[a], d))
			a++;
		h = 0;
		while (!is_delim(str[a + h], d) && str[a + h])
			h++;
		s[b] = malloc((h + 1) * sizeof(char));
		if (!s[b])
		{
			for (h = 0; h < b; h++)
				free(s[h]);
			free(s);
			return (NULL);
		}
		for (i = 0; i < h; i++)
			s[b][i] = str[a++];
		s[b][i] = 0;
	}
	s[b] = NULL;
	return (s);
}

/**
 * **strtow2 - A function that splits a string into words
 * @str: the string to be inputted
 * @d: the delimeter string
 * Return: pointer to an array of strings s if successful
 * NULL if unsuccessful
 */
char **strtow2(char *str, char d)
{
	int a, b, h, i, wordsnum = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (a = 0; str[a] != '\0'; a++)
		if ((str[a] != d && str[a + 1] == d) ||
				(str[a] != d && !str[a + 1]) || str[a + 1] == d)
			wordsnum++;
	if (wordsnum == 0)
		return (NULL);
	s = malloc((1 + wordsnum) * sizeof(char *));
	if (!s)
		return (NULL);
	for (a = 0, b = 0; b < wordsnum; b++)
	{
		while (str[a] == d && str[a] != d)
			a++;
		h = 0;
		while (str[a + h] != d && str[a + h] && str[a + h] != d)
			h++;
		s[b] = malloc((h + 1) * sizeof(char));
		if (!s[b])
		{
			for (h = 0; h < b; h++)
				free(s[h]);
			free(s);
			return (NULL);
		}
		for (i = 0; i < h; i++)
			s[b][i] = str[a++];
		s[b][i] = 0;
	}
	s[b] = NULL;
	return (s);
}
