#include "shell.h"

/**
 * _realloc - reallocates a memory block
 *
 * @ptr: void pointer
 * @old_size: unsigned int
 * @new_size: unsigned int
 *
 * Return: void pointer
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	unsigned int i;
	char *nptr = NULL;

	if (old_size == new_size)
		return (ptr);
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		ptr = NULL;
		return (NULL);
	}
	if (ptr == NULL)
	{
		nptr = malloc(new_size);

		if (nptr == NULL)
			return (NULL);
		return (nptr);
	}

	nptr = malloc(new_size);
	if (nptr == NULL)
		return (NULL);

	for (i = 0; i < old_size && i < new_size; i++)
		nptr[i] = ((char *)ptr)[i];

	free(ptr);
	ptr = NULL;
	return (nptr);
}
