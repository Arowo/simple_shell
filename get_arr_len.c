#include "shell.h"

/**
 * get_arr_len - calcualtes length of a string
 *
 * @str: string whose length is to be calculated
 *
 * Return: total length of the string
 */

int get_arr_len(char **str)
{
	int len_str = 0;
	int i = 0;

	while (str[i])
	{
		len_str++;
		i++;
	}

	return (len_str);
}
