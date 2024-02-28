#include "shell.h"

/**
 * main - entry point function for this program
 *
 * @argc :count of command & arguments passed
 * @argv:holds an array of arguments
 * @env: holds an array of environment variables
 *
 * Return: 0 on success
 */

int main(int argc, char **argv, char **env)
{
	char *buffer = NULL;
	size_t buf_len = 0;
	char *cmd[20];

	(void)argc;
	REPL(buffer, buf_len, cmd, argv, env);

	return (0);
}
