#include "main.h"

/**
* find_executable - Finds the executable for a given command
* @command: The command to find
* @command_path: The path to the executable
*
* Return: 0 on success, -1 on failure
*/
int find_executable(const char *command, char *command_path)
{
char *path, *dir, *full_path;
struct stat st;

path = getenv("PATH");
if (!path)
return (-1);

dir = strtok(path, ":");
while (dir != NULL)
{
full_path = malloc(strlen(dir) + strlen(command) + 2);
if (!full_path)
return (-1);

strcpy(full_path, dir);
strcat(full_path, "/");
strcat(full_path, command);

if (stat(full_path, &st) == 0)
{
strcpy(command_path, full_path);
free(full_path);
return (0);
}

free(full_path);
dir = strtok(NULL, ":");
}

return (-1);
}

/**
* execute_command - Executes a command
* @command: The command to execute
* @args: The arguments for the command
*/
void execute_command(const char *command, char *args[])
{
char command_path[PATH_MAX];

if (find_executable(command, command_path) == -1)
{
fprintf(stderr, "%s: Command not found\n", command);
exit(EXIT_FAILURE);
}

if (execve(command_path, args, environ) == -1)
{
perror(command);
exit(EXIT_FAILURE);
}
}
