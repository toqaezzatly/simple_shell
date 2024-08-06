#include "main.h"

/**
* execute_command - Executes a command by using execve
* @args: Array of arguments for the command
* @env: Array of environment variables
*
* Return: Nothing
*/
void execute_command(char **args, char **env)
{
pid_t pid = fork();

if (pid == 0)
{
if (execve(args[0], args, env) == -1)
{
perror("Error executing command");
exit(EXIT_FAILURE);
}
}
else if (pid > 0)
{
wait(NULL);
}
else
{
perror("Fork failed");
}
}

/**
* process_input - Processes the input command
* @input: The input string
*/
void process_input(char *input)
{
char *args[MAX_ARGUMENTS];
char *token;
int i = 0;

token = _strtok(input, " \t\r\n");
while (token != NULL && i < MAX_ARGUMENTS - 1)
{
args[i++] = token;
token = _strtok(NULL, " \t\r\n");
}
args[i] = NULL;

if (args[0] != NULL)
{
if (strcmp(args[0], "exit") == 0)
{
exit(EXIT_SUCCESS);
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
}
