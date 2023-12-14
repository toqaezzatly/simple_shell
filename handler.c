#include "shell.h"

/**
* interruptSigHandler - Signal handler for interrupt signals.
* @dummysignalnumber: just for compitability
* Return: void
*/
void interruptSigHandler(int dummysignalnumber)
{
int anotherdummy = 0;

dummysignalnumber = 0;
dummysignalnumber += anotherdummy;
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
/**
* process_Handler - hadle process
* @cmd: input string
*/
void process_Handler(char *cmd)
{
char *tokenized, *input[250], msg[50];
int cnt = 0;

tokenized = my_strtok(cmd, " ");
while (tokenized != NULL)
{
input[cnt++] = tokenized;
if (cnt >= 250)	/*max # character*/
{
msg = "msh ktb ktab omk hwo";
write(STDOUT_FILENO, msg, _str_len(msg));
return;
}
tokenized = my_strtok(NULL, " ");
}
input[cnt] = NULL;

if (cnt > 0)
{
if (my_strcmp(input[0], "exit") == 0)
{
msg = "Etl3 bra yallla";
write(STDOUT_FILENO, msg, _str_len(msg));
}
else if (my_strcmp(input[0], "env") == 0)
{
shellEnv();
}
else
{
_execcmd(input[0], input);
}
}
}

