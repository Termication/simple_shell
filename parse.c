#include "main.h"
/**
 * parse - Parses a string into an array of arguments
 * @user_input: The string to be parsed
 *
 * Return: An array of arguments parsed from the input string
 */
char **parse(char *user_input)
{
	char **args_list;
	char *arg;
	int index;
	int buffer_size = BUF_SIZE;

	if (user_input[0] == ' ' && user_input[_strlen(user_input)] == ' ')
		exit(0);
	if (user_input == NULL)
		return (NULL);
	args_list = malloc(sizeof(char *) * buffer_size);
	if (!args_list)
	{
		free(args_list);
		perror("hsh");
		return (NULL);
	}
	arg = _strtok(user_input, "\n\t\r\a ");
	for (index = 0; arg; index++)
	{
		args_list[index] = arg;
		arg = _strtok(NULL, "\n\t\r\a ");
	}
	args_list[index] = NULL;

	return (args_list);
}
