#include "main.h"

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

