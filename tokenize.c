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

/**
* tokenize - Splits a string into tokens based on delimiters
* @str: The string to be tokenized
* @delim: Delimiters to be used for splitting
*
* Return: Array of tokens
*/
char **tokenize(char *str, const char *delim)
{
char **tokens = NULL;
char *token;
size_t size = 0;
size_t i = 0;

token = strtok(str, delim);
while (token)
{
if (i >= size)
{
size += 10;
tokens = realloc(tokens, size * sizeof(char *));
if (!tokens)
return (NULL);
}
tokens[i++] = token;
token = strtok(NULL, delim);
}
tokens[i] = NULL;

return (tokens);
}
