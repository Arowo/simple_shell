#include "shell.h"

/**
 * print_env - prints each evironment variable on newline
 *
 * @env: holds an array the evironment varaibles
 *
 * Return: void
 */

void print_env(char **env)
{
	int i = 0;

	while (env[i])
	{
		_printf(env[i]);
		_printf("\n");
		i++;
	}
}
