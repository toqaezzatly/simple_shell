#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 256

int findExecutable(const char *command, char *commandPath)
{
	char *path = getenv("PATH");
	char *token;
	char *pathCopy = malloc(strlen(path) + 1);

	if (pathCopy == NULL)
	{
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}

	strcpy(pathCopy, path);
	token = strtok(pathCopy, ":");

	while (token != NULL)
	{
		snprintf(commandPath, MAX_COMMAND_LENGTH, "%s/%s", token, command);

		if (access(commandPath, X_OK) == 0)
		{
			free(pathCopy);
			return (1);
		}

		token = strtok(NULL, ":");
	}

	free(pathCopy);
	return (0);
}

void executeCommand(const char *command, char *args[])
{
	char *commandPath = malloc(MAX_COMMAND_LENGTH);

	if (commandPath == NULL)
	{
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}
	{
		pid_t childPid;
		int status;

		if (findExecutable(command, commandPath))
		{
			childPid = fork();
			if (childPid == -1)
			{
				perror("Fork failed");
				free(commandPath);
				exit(EXIT_FAILURE);
			}
			if (childPid == 0)
			{
				childProcess(commandPath, args);
			}
			else
			{
				parentProcess(childPid, &status);
			}
		}
		else
		{
			free(commandPath);
			return;
		}
	}
	free(commandPath);
}
void childProcess(const char *commandPath, char *args[]) {
    if (execv(commandPath, args) == -1) {
        perror("Execution failed");
        exit(EXIT_FAILURE);
    }
}

void parentProcess(pid_t childPid, int *status) {
    waitpid(childPid, status, 0);
    if (WIFEXITED(*status)) {
        printf("Child process exited with status %d\n", WEXITSTATUS(*status));
    } else {
        printf("Child process did not exit normally\n");
    }
}
