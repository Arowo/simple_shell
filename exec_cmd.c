#include "shell.h"

/**
 * execute_cmd - executes command by creating a child process
 *
 * @cmd: command bein executed
 * @argv: holds an array of arguments
 * @env: holds an array of environment variables
 *
 * Return: void
 */

void execute_cmd(char **cmd, char **argv, char **env)
{
	int status;
	int n = 1;

	if (cmd[0][0] != '/' && cmd[0][0] != '.')
	{
		n = add_path(&(cmd[0]), env);
		if (n == -1)
		{

			_printf(argv[0]);
			_printf(": No such file or directory\n");
			return;
		}
	}

	if (fork() == 0)
	{
		execve(cmd[0], cmd, env);
		_printf(argv[0]);
		_printf(": No such file or directory\n");
		free(cmd[0]);
		exit(0);

	}

	else
	{
		wait(&status);
		if (n == 1 || n == -1)
			return;
		free(cmd[0]);
	}

}
