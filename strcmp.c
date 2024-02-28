#include "shell.h"

/**
 * _strcmp - compares two strings
 *
 * @str1: pointer to the first string
 * @str2: pointer to the 2nd string
 *
 * Return: int
 */


int _strcmp(char *str1, char *str2)
{
	int i = 0;

	while (*str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}

	i = (*(const unsigned char *)str1 - *(const unsigned char *)str2);

	return (i);
}
