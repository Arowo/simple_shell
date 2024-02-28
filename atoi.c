#include "shell.h"

/**
 * _atoi - converts a character to an integer
 *
 * @str: pointer to the character
 *
 * Return: ascii value of the char
 */

int _atoi(char *str)
{
	int i;
	int ascii_value = 0;
	int sig = -1, brk = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '-')
			sig = sig * -1;

		if (str[i] >= '0' && str[i] <= '9')
		{
			ascii_value = ascii_value * 10;
			ascii_value -= (str[i] - '0');
			brk = 1;
		}
		else if (brk == 1)
			break;
	}

	ascii_value = sig * ascii_value;

	return (ascii_value);
}
