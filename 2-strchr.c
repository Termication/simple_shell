#include "main.h"

/**
 * _strchr - Locates the first occurrence of a character in a string
 * @s: The string to be searched
 * @c: The character to be located
 *
 * Return: Pointer to the first occurrence of the character in the string,
 *         or NULL if the character is not found
 */
char *_strchr(char *s, char c)
{
	int index = 0;

	for (; s[index] != '\0'; index++)
	{
		if (s[index] == c)
			return (&s[index]);
	}

	return (0);
}
