#include "shell.h"

/**
 * read_cmd - reads user-entered command
 *
 * @buffer: holds the command entered
 * @buf_len: length of the buffer
 *
 * Return: Returns n
 */

int read_cmd(char **buffer, size_t *buf_len)
{
	int n;

	n = getline(buffer, buf_len, stdin);

	if (n == -1)
	{
		free(*buffer);
		exit(0);
	}

	return (n);
}
