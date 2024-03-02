#include "main.h"
/**
 * search_lim - Checks if character is a delimiter.
 * @character: Character to check.
 * @delimiter: String of delimiters to compare.
 *
 * Return: 1 if character is a delimiter, else 0.
 */
unsigned int search_lim(char character, const char *delimiter)
{
	unsigned int index;

	for (index = 0; delimiter[index] != '\0'; index++)
	{
		if (character == delimiter[index])
			return (1);
	}
	return (0);
}
