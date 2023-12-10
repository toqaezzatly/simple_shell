#include "shell.h"
/**
 * interruptSigHandler - function to handle
 * 
 * Return: void
*/
void interruptSigHandler(void)
{
	interactiveMode("\n$");
}
/**
 * @commentHashHandler: truncate line from #
 * cmd: input command
 *
 * Return: handled cmd
*/
char *commentHashHandler(char *cmd)
{
	int index = 0;
	
	if (cmd == NULL)
		return (NULL);

	for (;cmd[index] != '\0'; index++)
	{
		if (cmd[i] == '#')
		{
			cmd[i] = '\0';
			break;
		}
	}
	return (cmd);
}
/**
 * EnterCmd - enter command
 * @num_read_chars: number of characters
 *
 * Return: the command line
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
			buffersize = 128;
			buffer = (char *)malloc(buffersize * sizeof(char));
			if (!buffer)
			{
				perror("malloc Failure");
				/*_myexit(EXIT_FAILURE);*/
			}
		}
		else
		{
			/*if malloc succeeded keep going and increase
			 * and double buffer size*/
			buffersize *= 2;
			/*Reallocate in heap after increae*/
			buffer = _myrealloc(buffer, buffersize * sizeof(char));
			/*Recheck allocation failure*/
			if (!buffer)
			{
					perror("realloc FAILUlre");
					/*_myexit(EXIT_FAILURE)*/
			}
		}
	}
	if (fgets(buffer + *num_read_chars, (int)(buffersize - *num_read_chars), stdin) == NULL) {
            /*Handle end-of-file*/
            if (feof(stdin)) {
                free(buffer);
                if (*num_read_chars == 0) {
                    /* No input received, exit gracefully*/
                   /*_myexit(EXIT_SUCCESS);*/
                }
                break;
            }

            /* Handle read error*/
            perror("read_command");
            /*_myexit(EXIT_FAILURE);*/
        }

        // Update the number of characters read
        *num_read_chars += _str_len(buffer + *num_read_chars);

        // Check if a newline character is present
        if (buffer[*num_read_chars - 1] == '\n') {
            // Remove the newline character
            buffer[*num_read_chars - 1] = '\0';
            break;
        }
    }	
}

