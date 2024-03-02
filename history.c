#include "main.h"
/**
 * past_arg - Appends user input to history file.
 * @user_input: User input string to append.
 *
 * Return: 1 on success, -1 on failure.
 *
 * Description: Appends user input to a
 * history file for tracking past arguments.
 */
int past_arg(char *user_input)
{
	char *file_name = ".hty";
	ssize_t file_descriptor, bytes_written;
	int length = 0;

	if (!file_name)
		return (-1);
	file_descriptor = open(file_name, O_CREAT | O_RDWR | O_APPEND, 00600);
	if (file_descriptor < 0)
		return (-1);
	if (user_input)
	{
		while (user_input[length])
			length++;
		bytes_written = write(file_descriptor, user_input, length);
		if (bytes_written < 0)
			return (-1);
	}
	return (1);
}
