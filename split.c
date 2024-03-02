#include "main.h"
/**
 * split - Splits string into tokens based on delimiters.
 * @input: String to split.
 *
 * Return: Array of split tokens.
 */
char **split(char *input)
{
	char **inputs;
	char *input_str;
	int index;
	int buffsize = BUF_SIZE;

	if (input[0] == ' ' && input[_strlen(input)] == ' ')
		exit(0);
	if (input == NULL)
		return (NULL);
	inputs = malloc(sizeof(char *) * buffsize);
	if (!inputs)
	{
		free(inputs);
		perror("hsh");
		return (NULL);
	}
	input_str = tokenize(input, ";&");
	for (index = 0; input_str; index++)
	{
		inputs[index] = input_str;
		input_str = tokenize(NULL, ";&");
	}
	inputs[index] = NULL;

	return (inputs);
}
