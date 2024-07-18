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
struct stat st;

if (stat(command, &st) == 0)
{
strcpy(command_path, command);
return (0);
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
if (execve(command, args, environ) == -1)
{
perror(command);
exit(EXIT_FAILURE);
}
}

