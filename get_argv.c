#include "shell.h"

#define MAX_ARGC 64

/**
 * initialize_argv - Function to allocate and initialize the argv array
 *
 * Return: argv if successful or NULL
 */
char **initialize_argv(void)
{
	char **argv = malloc(sizeof(char *) * MAX_ARGC);

	if (argv == NULL)
	{
		return (NULL);
	}
	memset(argv, 0, sizeof(char *) * MAX_ARGC);
	return (argv);
}

/**
 * append_token - Function to append a token to the argv array
 * @argc: argument count
 * @argv: argument vector
 * @token: token
 * @max_argc: max amount that can be accepted by argv
 *
 * Return: 0 if succesful or -ENOMEM on failure
 */
int append_token(size_t *argc,
		 char ***argv, const char *token, size_t *max_argc)
{
	if (*argc >= *max_argc)
	{
		char **new_argv = realloc(*argv,
					sizeof(char *) * (*max_argc *= 2));
		if (new_argv == NULL)
			return (-ENOMEM);

		*argv = new_argv;
	}

	(*argv)[(*argc)++] = _strdup(token);
	if ((*argv)[*argc - 1] == NULL)
		return (-ENOMEM);

	return (0);
}

/**
 * process_line - Function to process a single line,
 * handling multiline input if needed
 * @line: input
 * @argv: argument vector
 * @delim: delimiter
 *
 * Return: -1 on error or argc on success
 */
int process_line(char *line, char ***argv, const char *delim)
{
	size_t argc = 0;
	size_t max_argc = MAX_ARGC;
	char *token = strtok(line, delim);

	while (token != NULL)
	{
		trim(&token);

		if (append_token(&argc, argv, token, &max_argc) != 0)
			return (-1);

		token = strtok(NULL, delim);
	}

	return (argc);
}

/**
 * get_argv - collect input line and tokenize it
 * @argv: is updated with tokenized string
 *
 * Return: number of arguments parsed (argc) or -ENOMEM in case of an error
 */
int get_argv(char ***argv)
{
	size_t argc = 0;
	char *input_line = NULL;
	size_t input_line_len = 0;
	ssize_t read_len;
	const char *delim;
	int line_argc;
	int ismultiline = false;

	*argv = initialize_argv();
	if (*argv == NULL)
		free_argv(*argv), exit(-ENOMEM);

	do {
		/*prompt(1);*/
		read_len = getline(&input_line, &input_line_len, stdin);

		/* Ctrl+D pressed or end of input */
		if (read_len == -1)
			free(input_line), free_argv(*argv), exit(0);

		if (input_line[read_len - 1] == '\n')
			input_line[read_len - 1] = '\0';

		delim = (_strchr(input_line, ';') != NULL) ? ";" : " ";
		line_argc = process_line(input_line, argv, delim);

		if (line_argc == -1)
		{
			perror("process_line"), free(input_line);
			return (-ENOMEM);
		}

		argc += line_argc;
		input_line_len = 0;
		free(input_line);

	} while (ismultiline);

	input_line = NULL;
	return (argc);
}
