#ifndef SHELL_H
#define SHELL_H

#define MAX_COMMAND 15

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

void print_prompt(char **av, char **env);


#endif
