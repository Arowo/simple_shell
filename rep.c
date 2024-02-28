#include "shell.h"

/**
 * REPL - reads, evaluates, print and loops
 *
 * @buf: command entered by user
 * @buf_len: command length
 * @cmd : to hold an array of command and arguments
 * @argv: to hold an array of arguments
 * @env: to hold an array of environment variables
 *
 * Return: 0 on success
 */

int REPL(char *buf, size_t buf_len, char **cmd, char **argv, char **env)
{
	do {
		if (isatty(STDIN_FILENO))
			print_prompt();
		read_cmd(&buf, &buf_len);

		if (buf[0] == '\0' || _strcmp(buf, "\n") == 0)
		{
			continue;
		}
		if (_strcmp(buf, "exit\n") == 0)
		{
			free(buf);
			return (0);
		}
		if (_strcmp(buf, "env\n") == 0)
		{
			print_env(env);
			continue;
		}
		parser(buf, cmd);
		if (cmd[0] == NULL)
		{
			continue;
		}
		if (_strcmp(cmd[0], "exit") == 0 && get_arr_len(cmd) == 2)
		{
			exit_arg(cmd);
		}
		execute_cmd(cmd, argv, env);
	} while (1);
	return (0);
}
