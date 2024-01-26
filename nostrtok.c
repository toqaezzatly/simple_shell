#include "main.h"

/**
 * _strtok - strtok
 * @string: string
 * @delim: delimeter
 *
 * Return: pointer or NULL
*/

char *_strtok(char *string, const char *delim)
{
	return (strtok(string, delim));
}

