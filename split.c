#include "main.h"

/**
* split_line - Splits the command line into an array of tokens.
* @line: The command line to split.
* Return: An array of tokens, or NULL on error.
*/
char **split_line(char *line)
{
	int bufsize = BUFSIZE, position = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
	{
		perror("Allocation error");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, DELIMS);
	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		if (position >= bufsize)
		{
			bufsize += BUFSIZE;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				perror("Allocation error");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, DELIMS);
	}
	tokens[position] = NULL;
	return (tokens);
}
