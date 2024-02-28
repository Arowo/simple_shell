#include "shell.h"

/**
 * _memset - replaces the first n bytes of str with c
 *
 * @str: pointer to the string we are editing
 * @c: character we are replacing with
 * @n: index at which we end replacing
 *
 * Return: pointer to the edited string
 */

char *_memset(char *str, char c, unsigned int n)
{
	unsigned int i = 0;

	while (i < n)
	{
		str[i] = c;
		i++;
	}

	return (str);
}
