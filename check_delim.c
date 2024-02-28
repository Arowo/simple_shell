#include "shell.h"

/**
 * check_delim - checks for a delimeter match
 *
 * @c: Character being Checked
 * @str: String To Check
 *
 * Return: 1 Succes, 0 Failed
 */

unsigned int check_delim(char c, const char *str)
{
	unsigned int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (c == str[i])
			return (1);
	}

	return (0);
}
