#ifndef _MAIN_H_
#define _MAIN_H_

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

#define BUF_SIZE 4092
#define DELIMITER " \t\r\n\a"
#define PRINT_THIS(c) (write(STDERR_FILENO, c, _strlen(c)))



char *read_line(void);
char **split_line(char *line);
int execute(char **args);
int handle_builtin_commands(char **args);
char *find_command_in_path(char *command);
void handle_exit(void);
void execute_command(char **args);
void handle_builtin(char **args);
char *read_input_line(void);
void print_prompt(const char *prompt);
void handle_env(void);
int execute_if_command_exists(char **args);
ssize_t my_getline(char **lineptr, size_t *n, int fd);
char **create_exec_args(char *command_path);

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

#endif /*HEADER_H*/

