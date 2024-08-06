#include "main.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

/**
* _getline - Reads a line from standard input
* @lineptr: Pointer to the buffer where the line will be stored
* @n: Size of the buffer
*
* Return: Number of characters read, or -1 on failure
*/
ssize_t _getline(char **lineptr, size_t *n)
{
ssize_t nread;
char *buffer = NULL;
size_t bufsize = 0;

if (!lineptr || !n)
return (-1);

buffer = (char *)malloc(BUFSIZ);
if (!buffer)
return (-1);

nread = getline(&buffer, &bufsize, stdin);
if (nread == -1)
{
free(buffer);
return (-1);
}

*lineptr = buffer;
*n = nread;
return (nread);
}

