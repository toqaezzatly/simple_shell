#include "shell.h"
/**
 * main - Entry point
 * @argc: # of args
 * @argv: list of args
 *
 * Return: 0
*/
void main(int argc, char **argv)
{
	char *cmd, arguments;
	int num_read_chars, count = 0;

	while (1)
	{
		isatty(STD_FILENO) ? interactiveMode ("$") : (void) 0;
		/*singnal -> function to recieve the interupt signal CTRL+D*/
		signal(SIGINT, interruptSigHandler);/*handler*/
		count++;
		cmd = EnterCmd(&num_read_chars);

	}
}
