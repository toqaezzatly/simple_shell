#include "main.h"

/**
 * _getline - Reads a line from the standard input
 * @command_buff: The buffer to store the line
 * @n: The size of the buffer
 * @stdin: The input stream
 *
 * Return: The number of characters read, or -1 on failure
 */
ssize_t _getline(char **command_buff, size_t *n, FILE *_stdin)
{
    return (getline(command_buff, n, _stdin));
}

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
