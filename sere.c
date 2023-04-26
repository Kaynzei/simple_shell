#include "shell.h"

/**
 * is_cmd - A function that determines the executability of a file
 * @info: pointer to the parameter & return info struct
 * @path: the path to the file
 *
 * Return: 1 if is true & 0 if it is not
 */
int is_cmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dup_chars - A function for character duplication
 * @pathstr: pointer to the PATH string
 * @start: starting index parameter
 * @stop: stopping index parameter
 *
 * Return: pointer to the new buffer
 */
char *dup_chars(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int a = 0, h = 0;

	for (h = 0, a = start; a < stop; a++)
		if (pathstr[a] != ':')
			buf[h++] = pathstr[a];
	buf[h] = 0;
	return (buf);
}

/**
 * find_path - A function that finds the find_path cmd in the PATH string
 * @info: the info struct
 * @pathstr: pointer to the PATH string
 * @cmd: pointer to the cmd to find
 *
 * Return: the full path of cmd if found or NULL if it is not
 */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int a = 0, curr_pos = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[a] || pathstr[a] == ':')
		{
			path = dup_chars(pathstr, curr_pos, a);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_cmd(info, path))
				return (path);
			if (!pathstr[a])
				break;
			curr_pos = a;
		}
		a++;
	}
	return (NULL);
}
