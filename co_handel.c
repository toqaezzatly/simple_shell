#include "main.h"

/**
 * comment_handle - del comments
 * @command: str
 *
 * Return: command without comments
*/

void comment_handle(char *command)
{
	int a;

	for (a = 1; command[a] != '\0'; a++)
	{
		if ((command[a - 1] == ' ' || command[a - 1] == '\t') && command[a] == '#')

		{
			command[a] = '\0';
			break;
		}
	}
}

