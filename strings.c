#include "shell.h"
/**
 * _str_len - Calculate the length of a string.
 * @s: The input string.
 *
 * Return: The length of the string.
 */
int _str_len(const char *s)
{
	int length = 0;

	if (s == NULL)
		return (0);

	for (; s[length] != '\0'; length++)
		;
	return (length);
}



