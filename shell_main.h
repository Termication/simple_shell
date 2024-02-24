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

/*string handler functions*/
int _putchar(char c);
int _islower(int c);
int _isalpha(int c);
int _abs(int n);
int _isupper(int c);
int _isdigit(int c);
int _strlen(char *s);
void _puts(char *s);
char *_strcpy(char *dest, char *src);
int _atoi(char *s);
char *_strcat(char *dest, char *src);
char *_strncat(char *dest, char *src, int n);
char *_strncpy(char *dest, char *src, int n);
int _strcmp(char *s1, char *s2);
char *_memset(char *s, char b, unsigned int n);
char *_memcpy(char *dest, char *src, unsigned int n);
char *_strchr(char *s, char c);
unsigned int _strspn(char *s, char *accept);
char *_strpbrk(char *s, char *accept);
char *_strstr(char *haystack, char *needle);

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
