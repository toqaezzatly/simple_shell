#include "shell.h"
/**
 * interactiveMode - function to display prompt
 * @string: to be displayed 
 * Return: void
*/
void interactiveMode(char *string)
{
	write(1, string, _str_len(string));
}
