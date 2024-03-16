#include "main.h"
/**
 * custom_getline - Reads a line from standard input
 *
 * Return: A pointer to the string containing the input line
 */
char *custom_getline()
{
	int index, read_bytes, size = BUF_SIZE;
	char ch = 0, *buff, *line;

	buff = malloc(size);
	if (buff == NULL)
	{
		free(buff);
		return (NULL);
	}
	for (index = 0; ch != EOF && ch != '\n'; index++)
	{
		fflush(stdin);
		read_bytes = read(STDIN_FILENO, &ch, 1);
		if (read_bytes == 0)
		{
			free(buff);
			exit(EXIT_SUCCESS);
		}
		buff[index] = ch;
		if (buff[0] == '\n')
			return (_entereturn(buff));
		if (index >= size)
		{
			buff = realloc(buff, (size + 2));
			if (buff == NULL)
			{
				free(buff);
				return (NULL);
			}
		}
	}
	buff[index] = '\0';
	line = space(buff);
	free(buff);
	hash_attack(line);
	return (line);
}
