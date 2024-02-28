#include "shell.h"

/**
 * _strcpy - copies a string from src to dest
 *
 * @dest: pointer to the destination string
 * @src: pointer to the source string
 *
 * Return: pointer to the destination string
 */

char *_strcpy(char *dest, char *src)
{
	char *ptrSrc = src;
	int i = 0;

	while (*ptrSrc != '\0')
	{
		dest[i] = *ptrSrc;
		i++;
		ptrSrc++;
	}

	dest[i] = *ptrSrc;

	return (dest);
}
