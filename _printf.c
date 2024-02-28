#include "shell.h"


/**
 * _putchar - print a char
 * @ch: char
 * Return: int
 */


int _putchar(int ch)
{
	return (write(1, &ch, 1));
}


/**
 * _printf - produces output according to a format
 * @s: char pointer
 * Return: int
 */

int _printf(char *s)
{
	int len = 0;

	if (s == NULL)
		s = "(null)";

	while (*s)
	{
		_putchar(*s);
		len++;
		s++;
	}


	return (len);
}
