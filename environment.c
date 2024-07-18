#include "main.h"

/**
* print_environment - Prints the current environment
*/
void print_environment(void)
{
char **env = environ;

while (*env)
{
printf("%s\n", *env);
env++;
}
}

