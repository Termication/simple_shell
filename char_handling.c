#include "main.h"
/**
 * _entereturn - Free memory for string, return null terminator.
 * @st: String to free
 *
 * Return: Null terminator
 */
char *_entereturn(char *st)
{
	free(st);
	return ("\0");
}

/**
 * hash_attack - Remove text after '#' if surrounded by spaces.
 * @buffer: Input buffer to check.
 */
void hash_attack(char *buffer)
{
	int index;

	for (index = 0; buffer[index] != '\0'; index++)
	{
		if (buffer[index] == '#' && buffer[index - 1] ==
				' ' && buffer[index + 1] == ' ')
		{
			buffer[index] = '\0';
		}
	}
}
/**
 * space - Remove leading spaces from string.
 * @string: Input string to trim.
 *
 * Return: Modified string without leading spaces.
 *
 * Description: Remove leading spaces from input string.
 */
char *space(char *string)
{
	int index, position = 0;
	char *result;

	result = malloc(sizeof(char) * (_strlen(string) + 1));
	if (result == NULL)
	{
		free(result);
		return (NULL);
	}
	for (index = 0; string[index] == ' '; index++)
		;
	for (; string[index + 1] != '\0'; index++)
	{
		result[position] = string[index];
		position++;
	}
	result[position] = '\0';
	if (result[0] == '\0' || result[0] == '#')
	{
		free(result);
		return ("\0");
	}
	return (result);
}
