#include "shell.h"

/**
 * bfree - A function that frees a pointer and NULLs the address
 * @ptr: address of the pointer to be freed
 *
 * Return: 1 if pointer is freed successfully
 * 0 if unsuccessful
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
