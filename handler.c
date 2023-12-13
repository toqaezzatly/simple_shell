#include "shell.h"

/**
* interruptSigHandler - Signal handler for interrupt signals.
*
* Return: void
*/
void interruptSigHandler(void)
{
interactiveMode("\n$");
}

/**
* commentHashHandler - Truncate line from # in the command.
* @cmd: Input command.
*
* Return: Handled command.
*/
char *commentHashHandler(char *cmd)
{
int index = 0;

if (cmd == NULL)
return (NULL);

for (; cmd[index] != '\0'; index++)
{
if (cmd[index] == '#')
{
cmd[index] = '\0';
break;
}
}
return (cmd);
}

