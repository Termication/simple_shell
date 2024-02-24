#ifndef _SHELL_MAIN_H_
#define _SHELL_MAIN_H_

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <signal.h>


#define MAIN_BUF_SIZE 1024
#define READABLE_BUF_SIZE 512


/**
 * struct builtin_cmd - Defines a structure representing
 * a built-in command
 * and its associated functionality.
 * @cmd: The built-in command.
 * @func_ptr: A pointer to a function that implements
 * the command's functionality.
 */
typedef struct builtin_cmd
{
	char *cmd;
	int (*func_ptr)(char **args, int status);
} builtin_cmd;
