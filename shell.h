#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>
#include <stdbool.h>

#ifdef __GNUC__
#define UNUSED __attribute__((__unused__))
#endif

#define BUFFER_SIZE 128
#define PATH_MAX 4096

extern char **environ;

/**
 * struct builtin_t - builtin function
 * @name: name of builtin function
 * @func: pointer to builtin function
 */
typedef struct builtin_t
{
	char *name;
	int (*func)(char **argv);

} builtin_t;

int prompt(size_t signum);
void exit_with_error(int code, char *shell, const char *filename);
int execute_commands_from_file(char **argv);
char *handle_path(char *cmd);
int run_command(char **argv);
int execute_command(char **argv);

/*-----------builtin function------------------*/
int (*handle_builtin_func(char *s))(char **argv);
typedef int (*get_builtin)(char **argv);
int modifyenv(char **argv);
int exit_simple_shell(char **argv);
int printenv(char **argv UNUSED);
int change_working_dir(char **argv);
/*--------------------------------------------*/

void trim(char **str);
int get_argv(char ***argv);
void free_argv(char **argv);
int resize_argv(char ***argv, size_t *max_argc);
char *_getenv(const char *name);
char **create_env_table(char **envp);

ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
ssize_t readline(char **lineptr, size_t *n, int fd);
int resize_getline_buf(char **lineptr, size_t *n, size_t new_size);
int create_new_env(char *name, char *value);
int _setenv(char *name, char *value, int overwrite);
int _unsetenv(char *name);

size_t _strlen(const char *str);
char *_strchr(const char *str, int character);
char *_strtok(char *str, const char *delim);
char *_strcpy(char *dest, const char *src);
char *_strdup(const char *str);
char *_strcat(char *dest, char *str1, char *str2, char delim);
int _strncmp(const char *str1, const char *str2, size_t n);
int _strcmp(const char *str1, const char *str2);

char *_memset(char *s, char b, unsigned int n);
char *_memcpy(char *dest, char *src, unsigned int n);
void *_realloc(void *ptr, size_t size);

void cmd_not_found(char *cmd);

#endif /*
