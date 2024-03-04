#include "shell.h"

/**
 * change_working_dir - changes working directory
 * @argv: argument vector
 *
 * Return: 0 on success
 */
int change_working_dir(char **argv)
{
	char *path, old_dir[PATH_MAX], new_dir[PATH_MAX];

	if (argv[1] == NULL || _strcmp(argv[1], "~") == 0)
		path = _getenv("HOME");
	else if (_strcmp(argv[1], "-") == 0)
		path = _getenv("OLDPWD");
	else
		path = argv[1];

	if (access(path, X_OK) != 0)
		(path)
		    ? dprintf(STDERR_FILENO,
			      "./hsh: 1: cd: can't cd to %s\n", path)
		    : 0;

	/*Get old pwd*/
	if (getcwd(old_dir, sizeof(old_dir)) == NULL)
		return (-1);

	/*Change directory*/
	if (chdir(path) != 0)
		return (-1);

	/*Update old pwd*/
	if (_setenv("OLDPWD", old_dir, 1) != 0)
		return (-1);

	/*Get new pwd*/
	if (getcwd(new_dir, sizeof(new_dir)) == NULL)
		return (-1);

	/*Update new pwd*/
	if (_setenv("PWD", new_dir, 1) != 0)
		return (-1);

	return (0);
}

/**
 * printenv - prints environment variable
 * @argv: argument vector
 *
 * Return: 0 if successful
 */
int printenv(char **argv)
{
	int i = 0;

	(void)argv;

	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}

	return (0);
}

/**
 * exit_simple_shell - exit shell
 * @argv: argument vector
 *
 * Return: 0 on exit and status if exit code is given
 */
int exit_simple_shell(char **argv)
{
	char *exit_code = argv[1];

	if (!exit_code)
	{
		free_argv(argv);
		exit(0);
	}
	else
	{
		int code = atoi(exit_code);

		free_argv(argv);
		exit(code);
	}
	return (0);
}

/**
 * modifyenv - modifies current environment using setenv or unsetenv
 * @argv: argument vector
 *
 * Return: 0 if successful
 */
int modifyenv(char **argv)
{
	char *command = argv[0];
	int result;

	if (_strcmp(command, "setenv") == 0 &&
	    (argv[1] != NULL) && (argv[2] != NULL))
	{
		char *name = argv[1];
		char *value = argv[2];

		result = _setenv(name, value, 1);

		return (result);
	}

	if (_strcmp(command, "unsetenv") == 0 && (argv[1] != NULL))
	{
		char *name = argv[1];

		result = _unsetenv(name);

		return (result);
	}

	perror(": Environment not modified");
	return (-1);
}
