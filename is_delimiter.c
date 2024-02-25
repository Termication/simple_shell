#include "main.h"
#define MAX_ASCII 128

/**
 * is_delimiter - Checks if a character is a delimiter.
 * @c: The character to check.
 * @delimiters: String containing the delimiters.
 *
 * Return: 1 if the character is a delimiter, 0 otherwise.
 */
unsigned int is_delimiter(char c, const char *delimiters)
{
	static unsigned char delimiter_bitset[MAX_ASCII] = {0};

	int i;

	/* One-time initialization of the bit array */
	if (delimiter_bitset[0] == 0)
	{
		for (i = 0; delimiters[i] != '\0'; i++)
			delimiter_bitset[(unsigned char)delimiters[i]] = 1;
	}

	return (delimiter_bitset[(unsigned char)c]);
}

#include "header.h"

/**
 * read_user_input - Reads input from the standard input provided by the user.
 * Return: The input stored in a buffer.
 */
char *read_user_input()
{
	char *input_buffer = NULL;
	size_t buffer_size = 0;

	if (getline(&input_buffer, &buffer_size, stdin) == -1)
	{
		free(input_buffer);
		exit(EXIT_FAILURE);
	}

	return (input_buffer);
}

/**
 * handle_newline_character - Manages newline character
 * input in the provided string.
 * @input: The string to be processed.
 * Return: An empty string.
 */
char *handle_newline_character(char *input)
{
	free(input);
	return ("\0");
}

/**
 * remove_whitespace_prefix - Eliminates leading whitespace
 * from the input string.
 * @input_string: The string to be modified.
 * Return: The string without leading whitespace.
 */
char *remove_whitespace_prefix(char *input_string)
{
	char *trimmed_string = input_string;

	while (*trimmed_string == ' ')
		trimmed_string++;

	return (strdup(trimmed_string));
}

/**
 * remove_text_after_hashtag - Deletes content following
 * the '#' character in the input buffer.
 * @input_string: The input buffer to be processed.
 * Return: None.
 */
void remove_text_after_hashtag(char *input_string)
{
	char *hashtag_position = strchr(input_string, '#');

	if (hashtag_position)
		*hashtag_position = '\0';
}
