#include "shell.h"

/**
 * add_path - adds the corresponding path to user entered command
 *
 * @cmd: user entered command
 * @env: holds an array of env
 *
 * Return: an int value
 */

int add_path(char **cmd, char **env)
{
	char *path_arr, *str;
	char *path = _getenv("PATH", env);
	struct stat st;

	path_arr = _strtok(path, ":");

	while (path_arr)
	{
		str = build_path(*cmd, path_arr);

		if (stat(str, &st) == 0)
		{
			*cmd = _strdup(str);
			free(str);
			free(path);
			return (0);
		}

		path_arr = _strtok(NULL, ":");
		free(str);
	}

	free(path);

	return (-1);
}
