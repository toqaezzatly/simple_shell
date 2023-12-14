#include "shell.h"
/**
 * printnewline - print_NEWLINE
 *
 * Return: void
*/
void printnewline(void)
{
const char newline = '\n';
write(STDOUT_FILENO, &newline, 1);
}
/**
 * main - Entry point
 *
 * Return: 0
*/
int main(void)
{
	char cmd[255];
	int num_read_chars;

	while (1)
	{
		isatty(STDIN_FILENO) ? interactiveMode("$") : (void) 0;
		/*singnal -> function to recieve the interupt signal CTRL+D*/
		signal(SIGINT, interruptSigHandler);/*handler*/
		if (fgets(cmd, sizeof(cmd), stdin) == NULL)
		{
			printnewline();
			break;
		}
		num_read_chars = _str_len(cmd);
		if (num_read_chars > 0 && cmd[num_read_chars - 1] == '\n')
		{
			cmd[num_read_chars - 1] = '\0';
		}
		process_input(cmd);

	}
	return (0);
}
