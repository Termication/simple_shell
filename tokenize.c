#include "main.h"
/**
 * tokenize - Extracts tokens from string using delimiter.
 * @input_str: String to tokenize.
 * @delimiter: Delimiter for tokenization.
 *
 * Return: Pointer to the extracted token.
 */
char *tokenize(char *input_str, const char *delimiter)
{
	static char *ptr;
	static char *new_ptr;
	unsigned int index;

	if (input_str != NULL)
		new_ptr = input_str;
	ptr = new_ptr;
	if (ptr == NULL)
		return (NULL);
	for (index = 0; ptr[index] != '\0'; index++)
	{
		if (search_lim(ptr[index], delimiter) == 0)
			break;
	}
	if (new_ptr[index] == '\0' || new_ptr[index] == '#')
	{
		new_ptr = NULL;
		return (NULL);
	}
	ptr = new_ptr + index;
	new_ptr = ptr;
	for (index = 0; new_ptr[index] != '\0'; index++)
	{
		if (search_lim(new_ptr[index], delimiter) == 1)
			break;
	}
	if (new_ptr[index] == '\0')
		new_ptr = NULL;
	else
	{
		new_ptr[index] = '\0';
		new_ptr = new_ptr + index + 1;
		if (*new_ptr == '\0')
			new_ptr = NULL;
	}
	return (ptr);
}
