#include "main.h"
/**
 * handle_builtin_commands - Handles built-in shell commands.
 * @args: Array of tokens representing
 * the command and its arguments.
 *
 * If the command is "exit", exits the shell.
 * If the command is "cd", changes the current directory.
 * Return: none
 */

void handle_builtin_commands(char **args)
{
	if (strcmp(args[0], "exit") == 0)
	{
		exit(EXIT_SUCCESS);
	}
	else if (strcmp(args[0], "cd") == 0)
	{
		if (chdir(args[1]) != 0)
		{
			perror("simple_shell");
		}
	}
	else
	{
		return;
	}
}
