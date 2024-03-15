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
#include <stdbool.h>

#define BUF_SIZE 4092
#define DELIMITER " \t\r\n\a"
#define UNUSED __attribute__((unused))
#define PRINT_THIS(c) (write(STDERR_FILENO, c, _strlen(c)))
char **parse(char *user_input);
void dis_prompt(void);
int command_c(char **command, char *user_input, int count, char **arguments);
void signal_handler(int signal) ;
char *custom_getline();
char *_entereturn(char *st);
char *space(char *string);
void hash_attack(char *buffer);
unsigned int search_lim(char character, const char *delimiter);
char *tokenize(char *input_str, const char *delimiter);
char **split(char *input);
void print_digit(int number);
int echoing(char **arguments);
void dis_num(unsigned int number);
int past_arg(char *user_input);
char *create_path(char *file_token, char *file_value);
int path_command(char **command);
char *fetch_env(char *var_name);
char *create_path(char *file_token, char *file_value);
char *fetch_env(char *var_name);
void *an_array(void *a, int el, unsigned int len);
void closing_built(char **commands, char *input_line, FILE *file_descriptor);
void scan_file(char *file_name, char **arguments);
void file_exa(char *file_line, int line_count,
                FILE *file_ptr, char **arguments);
void error_file(char **program_args, int error_count);
void print_error(char *user_input, int loop_count, char **program_args);
void _prerror(char **program_args, int error_count, char **command);
void create_envi(char **envi);
void free_env(char **env);
int show_history(__attribute__((unused)) char **command, __attribute__((unused)) int status);
int echo_built_in(char **arguments, int status);
int dis_environment(__attribute__((unused)) char **cmd, __attribute__((unused)) int st);
int switch_directory(char **cmd, __attribute__((unused))int str);
char *_strncpy(char *dest, char *src, int n);
int _strlen(char *s);
int _putchar(char c);
int _atoi(char *s);
void _puts(char *str);
int _strcmp(char *s1, char *s2);
int _isalpha(int c);
void array_rev(char *arr, int len);
int intlen(int num);
char *_itoa(unsigned int n);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strchr(char *s, char c);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strdup(char *str);

void free_env(char **env);
void *fill_an_array(void *a, int el, unsigned int len);
char *_memcpy(char *dest, char *src, unsigned int n);
void *_calloc(unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void free_all(char **input, char *line);
void print_error(char *input, int counter, char **argv);
void _prerror(char **argv, int c, char **cmd);
void error_file(char **argv, int c);
extern char **environ;
void create_envi(char **envi);
void free_env(char **env);
char *build(char *token, char *value);
char *_getenv(char *name);
void help_env(void);
void help_setenv(void);
void help_unsetenv(void);
void help_history(void);
void help_all(void);
void help_alias(void);
void help_cd(void);
void help_exit(void);
void help_help(void);
int display_help(char **cmd, __attribute__((unused))int st);
int check_builtin(char **cmd);
int handle_builtin(char **cmd, int st);
void exit_bul(char **cmd, char *input, char **argv, int c, int stat);


/**
 * struct builtin_cmd - Defines a structure representing
 * a built-in command
 * and its associated functionality.
 * @cmd: The built-in command.
 * @func_ptr: A pointer to a function that implements
 * the command's functionality.
 */
typedef struct _builtin
{
	char *command;
	int (*function)(char **line, int st);
} builtin;

#endif /*HEADER_H*/

