#include "shell.h"

/**
 * _getenv - handles environmental variables and it's dir
 *
 * @buf: env to be return
 * @env_dir: array of env
 *
 * Return: env and values on Success, NULL on Failure
 */

char *_getenv(char *buf, char **env_dir)
{
	char *path;
	int i = 0;

	while (env_dir[i])
	{
		if (_strncmp(env_dir[i], buf, _strlen(buf)) == 0)
		{
			path = _strdup(env_dir[i]);
			return (path);
		}
		i++;
	}

	return (NULL);
}
