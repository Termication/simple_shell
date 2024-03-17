#include "main.h"

/**
 * _strncmp - Compares two strings
 * @s1: First string
 * @s2: Second string
 * @n: amount of characters to compare
 *
 * Return: Difference between the first non-matching characters in s1 and s2
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	if (s1 == NULL)
		return (-1);

	for (i = 0; i < n && s2[i]; i++)
	{
		if (s1[i] != s2[i])
		{
			return (1);
		}
	}
	return (0);
}
