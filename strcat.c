#include "shell.h"

/**
 * _strcat - appends source string str to dest
 *
 * @dest: pointer to the destination string
 * @src: pointer to the source string
 *
 * Return: pointer to the destination string
 */

char *_strcat(char *dest, char *src)
{
	int dest_len = _strlen(dest);

	while (*src != '\0')
	{
		dest[dest_len] = *src;

		dest_len++;
		src++;
	}

	dest[dest_len] = '\0';

	return (dest);
}
