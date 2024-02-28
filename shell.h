#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "str.h"

void print_prompt(void);
void parser(char *buffer, char **cmd);
int add_path(char **cmd, char **env);
void print_env(char **env);
int exit_arg222(char **cmd, char **argv, char *buffer);
int exit_arg(char **args);
int REPL(char *buf, size_t buf_len, char **cmd, char **argv, char **env);
int get_arr_len(char **str);
unsigned int check_delim(char c, const char *str);
int _atoi(char *str);
char *_strcpy(char *dest, char *src);
int _strcmp(char *str1, char *str2);
int read_cmd(char **buffer, size_t *buf_len);
void execute_cmd(char **cmd, char **argv, char **env);
int _printf(char *);
char *_strcat(char *dest, char *src);
int _strlen(char *str);
char *_strdup(char *str);
char *build_path(char *token, char *value);
char *_memset(char *str, char c, unsigned int n);
char *_getenv(char *buf, char **env_dir);
int _strncmp(char *str1, char *str2, unsigned int n);
char *_strtok(char *str, const char *delim);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

#endif
