#include "main.h"

/**
 * _strstr - Locates a substring in a string
 * @haystack: The string to be searched
 * @needle: The substring to search for
 *
 * Return: A pointer to the beginning of the located substring,
 * or NULL if the substring is not found.
 */
char *_strstr(char *haystack, char *needle)
{
	for (; *haystack != '\0'; haystack++)
	{
		char *current = haystack;
		char *pattern = needle;

		while (*current == *pattern && *pattern != '\0')
		{
			current++;
			pattern++;
		}

		if (*pattern == '\0')
			return (haystack);
	}

	return (0);
}
