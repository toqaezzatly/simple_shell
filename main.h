#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <dirent.h>
#include <limits.h>
#include <ctype.h>

#define MAX_COMMAND_LENGTH 1024

#define MAX_ARGUMENTS 100

extern char **environ;
/*
 * tokens_list - the tokens of the list
 * Description: token list
 * @parameter: str char
 *
 * Return: nothing
*/

typedef struct tokens_list
{
	char *token;
	struct tokens_list *next;
} token_node;

void print_environment(void);
int find_executable(const char *command, char *command_path);
int main(void);
char *_strtok(char *string, const char *delim);
ssize_t _getline(char **command_buff, size_t *n, FILE *_stdin);
void comment_handle(char *command);
void execute_command(const char *command, char *args[]);
void process_input(char *input);
void handle_commands(char *args[]);
void prompt_user(void);



#endif

