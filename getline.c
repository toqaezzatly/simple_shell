#include "main.h"

/**
 * _getline - implementation of it
 * @command_buff: buffer
 * @n: girth
 * @_stdin: file
 *
 * Return: num of char
*/

ssize_t _getline(char **command_buff, size_t *n, FILE *_stdin)
{
	return (getline(command_buff, n, _stdin));
}

