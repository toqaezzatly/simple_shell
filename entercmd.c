#include <stdio.h>
#include <stdlib.h>

#define INITIAL_BUFFER_SIZE 128
/*
* AllocateBuffer - Allocates memory for a character buffer.
* @size: Size of the buffer to be allocated.
*
* Return: A pointer to the allocated buffer.
*/
char *AllocateBuffer(size_t size) 
{
return (char *)malloc(size * sizeof(char));
}
/*
* ReallocateBuffer - Reallocates memory for a character buffer.
* @buffer: Pointer to the existing buffer.
* @buffersize: Pointer to the size of the existing buffer.
*
* Return: A pointer to the reallocated buffer.
*/
char *ReallocateBuffer(char *buffer, size_t *buffersize)
{
*buffersize *= 2;
return (char *)realloc(buffer, *buffersize * sizeof(char));
}
/*
* HandleMemoryAllocationFailure - Handles failure in memory allocation.
* @buffer: Pointer to the buffer to be freed.
*
* Description: This function prints an error message for memory allocation
* failure, frees the allocated buffer, and exits the program with failure.
*/
void HandleMemoryAllocationFailure(char *buffer)
{
perror("Memory Allocation Failure");
free(buffer);
exit(EXIT_FAILURE);
}
/*
* HandleReadCommandFailure - Handles failure in reading the command.
* @buffer: Pointer to the buffer to be freed.
*
* Description: This function prints an error message for command reading
* failure, frees the allocated buffer, and exits the program with failure.
*/
void HandleReadCommandFailure(char *buffer) 
{
perror("read_command");
free(buffer);
exit(EXIT_FAILURE);
}
/*
* EnterCmd - Enter command.
* @num_read_chars: Number of characters.
*
* Return: The command line.
*/
char *EnterCmd(int *num_read_chars)
{
char *buffer = NULL;
size_t buffersize = 0;
*num_read_chars = 0;

while (1) 
{
if (!buffer)
{
buffersize = INITIAL_BUFFER_SIZE;
buffer = AllocateBuffer(buffersize);
if (!buffer)
{
HandleMemoryAllocationFailure(buffer);
}
} else
{
buffer = ReallocateBuffer(buffer, &buffersize);
if (!buffer)
{
HandleMemoryAllocationFailure(buffer);
}
}

if (fgets(buffer + *num_read_chars, (int)(buffersize - *num_read_chars), stdin) == NULL)
{
if (feof(stdin)) 
{
free(buffer);
if (*num_read_chars == 0)
{
/* No input received, exit gracefully */
exit(EXIT_SUCCESS);
}
break;
}
HandleReadCommandFailure(buffer);
}

*num_read_chars += strlen(buffer + *num_read_chars);

if (buffer[*num_read_chars - 1] == '\n')
{
buffer[*num_read_chars - 1] = '\0';
break;
}
}

/* Assuming a return value here */
return buffer;
}

