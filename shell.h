#ifndef SHELL_H
#define SHELL_H
/*needed libraries*/
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>
#include <signal.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stddef.h>


/*-------------prompt.c--------------*/
void interactiveMode(char *string);



/*--------------string.c------------*/
int _str_len(const char *s);
char *my_strtok(char *str, const char *delim);
int my_strcmp(const char *str1, const char *str2);
/*-------------handler.c-------------*/
void interruptSigHandler(int dummysignalnumber);
char *commentHashHandler(char *cmd);
char *EnterCmd(int *num_read_chars);
void process_Handler(char *cmd);

/*--------------------main.c-----------------*/
void printnewline(void);
int findExecutable(const char *command, char *commandPath;
void executeCommand(const char *command, char *args[]);

#endif
