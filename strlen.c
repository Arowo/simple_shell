#include "shell.h"

/**
 * _strlen - calculates the length of a string
 *
 * @str: pointer to the string
 *
 * Return: length of the string
 */

int _strlen(char *str)
{
	int len = 0;

	while (*str != '\0')
	{
		len++;
		str++;
	}

	return (len);
}
