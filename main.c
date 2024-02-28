#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "main.h"

/**
* Prints the shell prompt.
* 
* @param prompt The prompt to be printed.
*/
void print_prompt(const char *prompt)
{
	size_t prompt_len = strlen(prompt);
	write(STDOUT_FILENO, prompt, prompt_len);
}

/**
* Reads a line of input from the user.
* 
* @return The input line.
*/
char *read_input_line(void)
{
	char *line = NULL;
	ssize_t bufsize = 0;
	getline(&line, &bufsize, stdin);
	return line;
}

/**
* Handles built-in shell commands.
* 
* @param args The array of arguments.
*/
void handle_builtin(char **args)
{
	if (strcmp(args[0], "exit") == 0)
	{
		handle_exit();
	}
	else if (strcmp(args[0], "cd") == 0)
	{
	}
	else if (strcmp(args[0], "env") == 0)
	{
		handle_env();
	}
	else
	{
	}
}

/**
* execute_command - Executes a command.
* 
* @args: The array of arguments representing the command.
*/
void execute_command(char **args)
{
	if (execute(args) == -1)
	{
		perror("simple_shell");
	}
}

/**
* Main - function of the simple shell.
*/
int main(void)
{
	char *line;
	char **args;
	char prompt[] = "$ ";

	while (1)
	{
		print_prompt(prompt);
		line = read_input_line();

		if (line == NULL)
		{ /* Handle Ctrl-D */
			write(STDOUT_FILENO, "\n", 1);
			break;
		}

		args = split_input_line(line);
		handle_builtin(args);

		if (execute(args) == -1)
		{ 
			char *command_path = find_command_path(args[0]);
			if (command_path)
			{
				args[0] = command_path;
				execute_command(args);
				free(command_path);
			}
			else
			{
				perror("simple_shell");
			}
		}

		free(line);
		free(args);
	}

	return (0);
}
