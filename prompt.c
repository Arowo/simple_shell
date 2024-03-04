#include "shell.h"

/**
 * prompt - prints prompt to the output
 * @signum: signal number
 *
 * Return: 1
 */
int prompt(size_t signum)
{
	char *prompt = (!signum) ? "$ " : "\n$ ";
	size_t prompt_len = _strlen(prompt);

	if (signum == 1)
		prompt = "> ";

	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, prompt, prompt_len);
		fflush(stdout); /*Ensure the prompt is displayed immediately*/
	}
	return (1);
}

/**
 * free_argv - frees an array of strings
 * @argv: pointer to an array of strings
 */
void free_argv(char **argv)
{
	size_t i = 0;

	if (argv == NULL)
		return;

	while (argv[i] != NULL)
	{
		free(argv[i++]);
	}
	free(argv);
}

/**
 * resize_argv - Resizes the argv array by doubling its size
 * @argv: pointer to an array of strings
 * @max_argc: size of argv
 *
 * Return: 0 success, 1 failure
 */
int resize_argv(char ***argv, size_t *max_argc)
{
	char **new_argv;
	size_t new_size, i;
	*max_argc *= 2;

	new_size = *max_argc * sizeof(char *);
	new_argv = _realloc(*argv, new_size);
	if (new_argv == NULL)
		return (-ENOMEM);

	/*Copy existing pointers to the new array*/
	for (i = 0; i < *max_argc / 2; i++)
	{
		new_argv[i] = (*argv)[i];
	}

	free_argv(*argv); /*Free the old array*/
	*argv = new_argv;

	return (0);
}

/**
 * trim - Trim leading and trailing whitespace or quotes from a string
 * @str: string
 */
void trim(char **str)
{
	char *start = *str;
	char *end = *str + _strlen(*str) - 1;

	/*Find the index of the first non-whitespace character*/
	while (*start && (*start == ' ' || *start == '"' || *start == '\t'))
	{
		start++;
	}

	/*Find the index of the last non-whitespace character*/
	while (end > start && (*end == ' ' || *end == '"' || *end == '\t'))
	{
		end--;
	}

	/*Null-terminate the trimmed string*/
	end[1] = '\0';

	/*Update the pointer to the trimmed string*/
	*str = start;
}
