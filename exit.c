#include "shell.h"

/**
 * exit_arg - Exit the shell
 *
 * @args: List of arguments. Unused
 *
 * Return: Always returns 0, to signal exit status
 */

int exit_arg(char **args)
{
	(void)args;
	exit(EXIT_SUCCESS);
	return (0);
}
