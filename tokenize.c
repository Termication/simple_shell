#include "main.h"

/**
 * tokenize_command - Tokenizes the command line input by the user.
 * @command_line: The command line input by the user.
 * @args: Array to store the tokens.
 * Return:
 *   - The number of tokens (including the command itself).
 */
int tokenize_command(char *command_line, char **args)
{
	char *token;
	int i = 0;

	/* Tokenize the command line*/
	token = strtok(command_line, " ");
	while (token != NULL)
	{
		args[i++] = token;
		token = strtok(NULL, " ");
	}
	args[i] = NULL;  /*Null-terminate the array*/

	return (i);
}
