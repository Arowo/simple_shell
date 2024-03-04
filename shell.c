#include "shell.h"

/**
 * handle_signal - handle signals
 * @sigint: signal number
 */
void handle_signal(int sigint)
{
	prompt(sigint);
	if (sigint == 2)
	{
		errno = 130;
	}
}

/**
 * main - Entry point
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 success
 */
int main(int argc, char **argv)
{
	signal(SIGINT, handle_signal);

	if (argc > 1)
	{
		exit(execute_commands_from_file(argv));
	}

	while (prompt(0))
	{
		argc = get_argv(&argv);
		if (argc > 0)
		{
			argv[argc] = NULL;
			run_command(argv);
			free_argv(argv);
		}
	}
	return (0);
}

/**
 * exit_with_error - writes message to stderr and exits with error code
 * @code: error code
 * @shell: shell program
 * @filename: file name
 */
void exit_with_error(int code, char *shell, const char *filename)
{
	dprintf(STDERR_FILENO, "%s: 0: Can't open %s\n", shell, filename);
	exit(code);
}


/**
 * execute_commands_from_file - Execute commands from a file
 * @argv: argument vector
 *
 * Description: Reads commands from the specified file and executes them
 *
 * Return: 0 if successful, -1 on error
 *
 */
int execute_commands_from_file(char **argv)
{
	char command[1000];
	int fd;
	ssize_t bytes_read;

	if (access(argv[1], R_OK) != 0)
		exit_with_error(127, argv[0], argv[1]);

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror((char *)EACCES);
		exit(127);
	}

	while ((bytes_read = read(fd, command, sizeof(command))) > 0)
	{
		pid_t child_p = fork();

		if (child_p == -1)
		{
			perror("Error creating process");
			return (1);
		}

		if (child_p == 0)
		{
			char *args[] = {"/bin/sh", "-c", NULL, NULL};

			command[bytes_read] = '\0';
			args[2] = command;

			if (execve(args[0], args, environ) == -1)
			{
				perror("execve error");
			}
		}
	}

	close(fd), exit(0);
	return (0);
}

/**
 * run_command - this function is responsible for
 * directing the flow of execution
 * @argv: argument vector
 *
 * Return: 0 if succesful and -1 if unsuccessful
 */
int run_command(char **argv)
{
	get_builtin execute_builtin;
	int run_status;

	execute_builtin = handle_builtin_func(argv[0]);
	if (execute_builtin)
		run_status = execute_builtin(argv);
	else
		run_status = execute_command(argv);

	return (run_status);
}
