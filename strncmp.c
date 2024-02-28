#include "shell.h"

/**
 * _strncmp - compares two strings
 *
 * @str1: pointer to the first string
 * @str2: pointer to the 2nd string
 * @n: the numbver of characters to be compared
 *
 * Return: int
 */

int _strncmp(char *str1, char *str2, unsigned int n)
{
	while (*str1 && (*str1 == *str2) && n)
	{
		str1++;
		str2++;
		n--;
	}
	if (n == 0)
		return (0);
	return (*(const unsigned char *)str1 - *(const unsigned char *)str2);
}
