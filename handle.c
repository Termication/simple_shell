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

int handle_builtin_commands(char **args)
{
	if (strcmp(args[0], "exit") == 0)
	{
		return (1);
	}
	else if (strcmp(args[0], "cd") == 0)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
