#include "shell.h"
#include <unistd.h>
#include <string.h>

void print_environment(void)
{
	char *env = getenv("PATH");

	if (env == NULL)
	{
		fprintf(stderr, "PATH environment variable not set\n");
		return;
	}

	write("%s\n", env);
}

