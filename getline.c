#include "main.h"

/**
* _getline - Reads a line from the standard input
* @command_buff: The buffer to store the line
* @n: The size of the buffer
* @_stdin: The input stream
*
* Return: The number of characters read, or -1 on failure
*/
ssize_t _getline(char **command_buff, size_t *n, FILE *_stdin)
{
return (getline(command_buff, n, _stdin));
}

