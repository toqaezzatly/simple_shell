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



/*-------------handler.c-------------*/
void interruptSigHandler(void);
char *commentHashHandler(char *cmd);
char *EnterCmd(int *num_read_chars);

#endif
