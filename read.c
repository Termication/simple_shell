#include "main.h"

/**
 * read_line - Reads a line of input from the user.
 * Return: The line of input, or NULL on error or end of file.
 */
char *read_line(void)
{
	char *line = NULL;
	size_t len = 0;

	if (my_getline(&line, &len, STDIN_FILENO) == -1)
	{
		perror("my_shell: error reading input");
		return (NULL);
	}

	return (line);
}
