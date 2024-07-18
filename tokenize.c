#include "main.h"

/**
* _strtok - Tokenizes a string based on delimiters
* @string: The string to tokenize
* @delim: The delimiters
*
* Return: The next token, or NULL if there are no more tokens
*/
char *_strtok(char *string, const char *delim)
{
static char *last;
char *token;

if (string == NULL)
string = last;

string += strspn(string, delim);
if (*string == '\0')
{
last = string;
return (NULL);
}

token = string;
string = strpbrk(token, delim);
if (string == NULL)
{
last = token + strlen(token);
}
else
{
*string = '\0';
last = string + 1;
}

return (token);
}

