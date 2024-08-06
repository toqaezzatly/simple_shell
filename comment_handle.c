#include "main.h"

/**
* comment_handle - Handles comments in the command
* @command: The command string
*/
void comment_handle(char *command)
{
char *comment = strchr(command, '#');

if (comment)
*comment = '\0';
}

