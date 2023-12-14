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
/**
* my_strcmp - Compare two strings.
* @str1: The first string to be compared.
* @str2: The second string to be compared.
*
* Return: 0, 1 , -1
*/
int my_strcmp(const char *str1, const char *str2)
{
if (str1 == NULL || str2 == NULL)
return (EXIT_FAILURE);

while (*str1 && (*str1 == *str2))
{
str1++;
str2++;
}

return (*(unsigned char *)str1 - *(unsigned char *)str2);
}
/**
* my_strtok - Tokenize a string.
* @str: The string to be tokenized.
* @delim: The delimiter used to tokenize the string.
*
* Return: A pointer to the next token or NULL if there are no more tokens.
*/
char *my_strtok(char *str, const char *delim)
{
char *lastToken = NULL;
char *tokenEnd;

if (str != NULL)
{
lastToken = str;
}
else
{
if (lastToken == NULL)
{
return (NULL); /* No more tokens to return */
}
str = lastToken;
}

/* Find the beginning of the next token (skip leading delimiters) */
str += strspn(str, delim);

/* If the remaining string is empty, no more tokens */
if (*str == '\0')
{
lastToken = NULL;
return (NULL);
}

/* Find the end of the token */
tokenEnd = str + strcspn(str, delim);

/* If the token is not at the end of the string, terminate it */
if (*tokenEnd != '\0')
{
*tokenEnd = '\0';
lastToken = tokenEnd + 1;
}
else
{
lastToken = NULL;
}

return (str);
}

