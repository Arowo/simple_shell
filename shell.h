#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_COMMAND_LENGTH 100

void display_prompt()
{
    printf("#cisfun$ ");
    fflush(stdout);
}

void execute_command(char *command)
{
    if (access(command, X_OK) == 0)
    {
        pid_t pid = fork();

        if (pid == -1)
        {
            perror("fork");
            return;
        }
        else if (pid == 0)
        {
            // Child process
            char *args[] = {command, NULL};
            execve(command, args, NULL);
            perror("execve");
            exit(EXIT_FAILURE);
        }
        else
        {
            // Parent process
            int status;
            waitpid(pid, &status, 0);
        }
    }
    else
    {
        printf("%s: No such file or directory\n", command);
    }
}

int main()
{
    char command[MAX_COMMAND_LENGTH];

    while (1)
    {
        display_prompt();

        if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
        {
            printf("\n");
            break;
        }

        command[strcspn(command, "\n")] = '\0'; // Remove the newline character

        if (strcmp(command, "exit") == 0)
        {
            break;
        }

        execute_command(command);
    }

    return 0;
}
