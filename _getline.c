#include "shell.h"

static char read_buffer[BUFFER_SIZE];
static ssize_t buffer_index;

/**
 * resize_getline_buf - resize the memory size of the buffer
 * @lineptr: buffer
 * @n: The buffer size allocated to the line
 * @new_size: new size of memory
 *
 * Return: 0 on success, -ENOMEM on failure
 */
int resize_getline_buf(char **lineptr, size_t *n, size_t new_size)
{
	char *newline = _realloc(*lineptr, new_size);

	if (newline == NULL)
	{
		free(*lineptr);
		return (-ENOMEM);
	}
	*lineptr = newline;
	*n = new_size;

	return (0);
}

/**
 * _getline - retrieves a line from stream
 * @lineptr: The line is stored in the memory pointed to by the lineptr
 * @n: The buffer size allocated to the line
 * @stream: The file stream the line is gotten from
 *
 * Return: The amount of bytes read is returned on success,
 * on error or EOF -1 is returned
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	if (n == NULL || stream == NULL)
		return (-EINVAL);

	if (*lineptr == NULL || *n <= 0)
	{
		*n = BUFFER_SIZE;
		*lineptr = malloc(*n);
		if (*lineptr == NULL)
			return (-ENOMEM);

		_memset(*lineptr, 0, BUFFER_SIZE);
	}

	return (readline(lineptr, n, stream->_fileno));
}

/**
 * readline - reads a line from a stream and stores it into lineptr
 * @lineptr: pointer to where the read line will be stored
 * @n: size of allocated buffer
 * @fd: file descriptor for stream to read from
 *
 * Return: total amount bytes read on Success
 */
ssize_t readline(char **lineptr, size_t *n, int fd)
{
	ssize_t read_bytes = 0;
	ssize_t total_bytes_read = 0;

	buffer_index = 0;

	while (1)
	{
		/*Check if buffer needs to be resized*/
		if (total_bytes_read >= (ssize_t)(*n - 1) &&
		    resize_getline_buf(lineptr, n, (*n * 2)))
		{
			return (-1); /*Memory allocation Failed*/
		}

		/*If the buffer is empty fill it, and reset the index to 0*/
		if (buffer_index >= read_bytes)
		{
			read_bytes = read(fd, read_buffer, BUFFER_SIZE);
			if (read_bytes <= 0)
				return ((total_bytes_read == 0) ? EOF : -1);
		}

		if (read_buffer[buffer_index] == '\n')
		{
			/**
			 * Set Null Terminating character immediately
			 * after the last character
			 */
			(*lineptr)[total_bytes_read + 1] = '\0';

			/*Reset Buffer*/
			buffer_index = 0;
			_memset(read_buffer, 0, BUFFER_SIZE);
			return (total_bytes_read + 1);
		}

		(*lineptr)[total_bytes_read++] = read_buffer[buffer_index++];
	}
}
