#include "main.h"
#include <stdbool.h>
#include <stdlib.h>

bool is_interactive = false;

void print_environment(void)
{
    char *env = getenv("PATH");

    if (env == NULL)
    {
        printf("PATH environment variable not set\n");
        return;
    }

    printf("%s\n", env);
}

int find_executable(const char *command, char *command_path)
{
    char *path = getenv("PATH");
    char *token;
    char *path_copy = malloc(strlen(path) + 1);

    if (path_copy == NULL)
    {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    strcpy(path_copy, path);
    token = strtok(path_copy, ":");

    while (token != NULL)
    {
        snprintf(command_path, MAX_COMMAND_LENGTH, "%s/%s", token, command);

        if (access(command_path, X_OK) == 0)
        {
            free(path_copy);
            return 1;
        }

        token = strtok(NULL, ":");
    }

    free(path_copy);
    return 0;
}

void child_process(const char *command_path, char *args[])
{
    if (execvp(command_path, args) == -1)
    {
        perror("Command execution failed");
        exit(EXIT_FAILURE);
    }
}

void parent_process(pid_t child_pid, int *status)
{
    waitpid(child_pid, status, 0);
    if (WIFEXITED(*status))
    {
        int exit_status = WEXITSTATUS(*status);
        printf("Command exited with status %d\n", exit_status);
    }
    else if (WIFSIGNALED(*status))
    {
        int signal_number = WTERMSIG(*status);
        printf("Command terminated by signal %d\n", signal_number);
    }
}

void execute_command(const char *command, char *args[])
{
    char *command_path = malloc(MAX_COMMAND_LENGTH);

    if (command_path == NULL)
    {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    {
    pid_t child_pid;
    int status;

    if (find_executable(command, command_path))
    {
        child_pid = fork();
        if (child_pid == -1)
        {
            perror("Fork failed");
            free(command_path);
            exit(EXIT_FAILURE);
        }

        if (child_pid == 0)
        {
            child_process(command_path, args);
        }
        else
        {
            parent_process(child_pid, &status);
        }
    }
    else
    {
        free(command_path);
        return;
    }
    }
    free(command_path);
}

void process_input(char *input)
{
    char *token, *args[MAX_ARGUMENTS];
    int arg_count = 0;

    token = strtok(input, " ");
    while (token != NULL)
    {
        args[arg_count] = token;
        arg_count++;

        if (arg_count >= MAX_ARGUMENTS)
        {
            printf("Too many arguments\n");
            return;
        }
        token = strtok(NULL, " ");
    }
    args[arg_count] = NULL;

    if (arg_count > 0)
    {
        handle_commands(args);
    }
}

void handle_commands(char *args[])
{
    if (strcmp(args[0], "exit") == 0)
    {
        printf("Exiting the shell\n");
        if (is_interactive)
        {
            exit(EXIT_SUCCESS);
        }
    }
    else if (strcmp(args[0], "env") == 0)
    {
        print_environment();
    }
    else
    {
        execute_command(args[0], args);
    }
}

void prompt_user(void)
{
    if (is_interactive)
    {
        printf("$ ");
        fflush(stdout);
    }
}

int main(void)
{
    char input[MAX_COMMAND_LENGTH];
    size_t input_length;

    is_interactive = isatty(STDIN_FILENO);

    while (1)
    {
        prompt_user();

        if (fgets(input, sizeof(input), stdin) == NULL)
        {
            printf("\n");
            break;
        }

        input_length = strlen(input);

        if (input_length > 0 && input[input_length - 1] == '\n')
        {
            input[input_length - 1] = '\0';
        }

        process_input(input);
    }

    return EXIT_SUCCESS;
}

