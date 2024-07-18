#include "main.h"

/**
* prompt_user - Displays the prompt and waits for the user input
*/
void prompt_user(void)
{
char *command = NULL;
size_t len = 0;
ssize_t nread;

while (1)
{
printf("#cisfun$ ");
nread = _getline(&command, &len, stdin);
if (nread == -1)
{
if (feof(stdin))
{
free(command);
exit(EXIT_SUCCESS);
}
perror("getline");
free(command);
exit(EXIT_FAILURE);
}
comment_handle(command);
process_input(command);
}
}

