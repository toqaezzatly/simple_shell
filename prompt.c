#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
* prompt_user - Prompts the user for input and executes commands
*
* Return: Nothing
*/
void prompt_user(void)
{
char *line = NULL;
size_t len = 0;
ssize_t nread;
char **args;
char *token;
char *delim = " \t\r\n";

while (1)
{
printf("#cisfun$ ");
nread = _getline(&line, &len);
if (nread == -1)
{
perror("getline");
exit(EXIT_FAILURE);
}

/* Handle empty input */
if (nread == 1 && line[0] == '\n')
continue;

args = tokenize(line, delim);
if (args && args[0])
{
execute_command(args, environ);
}

free(line);
line = NULL;
len = 0;
}
}
