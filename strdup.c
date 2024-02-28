#include "shell.h"

/**
 * _strdup - creates a duplicate A String
 *
 * @str: pointer string the string we are duplicating
 *
 * Return: pinter to the duplucated string or NULL
 */

char *_strdup(char *str)
{
	size_t str_len, i;
	char *str_dup;

	str_len = _strlen(str);

	str_dup = malloc(sizeof(char) * (str_len + 1));
	if (!str_dup)
	{
		return (NULL);
	}

	for (i = 0; i <= str_len; i++)
	{
		str_dup[i] = str[i];
	}

	return (str_dup);
}
