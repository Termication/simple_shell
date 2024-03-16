#include "main.h"

/**
 * echo_built_in - Handles special echo cases.
 * @arguments: The array of command arguments.
 * @status: The status of the last command executed.
 *
 * Processes special cases for echo command. Returns 1 if handled,
 * otherwise prints custom echo and returns 0.
 */
int echo_built_in(char **arguments, int status)
{
	char *env_path;
	unsigned int parent_pid = getppid();

	if (_strncmp(arguments[1], "$?", 2) == 0)
	{
		print_digit(status);
		PRINT_THIS("\n");
	}
	else if (_strncmp(arguments[1], "$$", 2) == 0)
	{
		print_digit(parent_pid);
		PRINT_THIS("\n");
	}
	else if (_strncmp(arguments[1], "$PATH", 5) == 0)
	{
		env_path = fetch_env("PATH");
		PRINT_THIS(env_path);
		PRINT_THIS("\n");
		free(env_path);
	}
	else
		return (echoing(arguments));

	return (1);
}

/**
 * show_history - Displays command history.
 * @command: Command array.
 * @status: Status of last command.
 *
 * Reads and prints command history. Returns -1 on failure.
 *
 * Return: 0 on success, -1 on failure.
 */
int show_history(UNUSED char **command,UNUSED int status)
{
	char *filename = ".hty";
	FILE *file_ptr;
	char *line = NULL;
	size_t len = 0;
	int count = 0;
	char *error;

	file_ptr = fopen(filename, "r");
	if (file_ptr == NULL)
		return (-1);
	while ((getline(&line, &len, file_ptr)) != -1)
	{
		count++;
		error = _itoa(count);
		PRINT_THIS(error);
		free(error);
		PRINT_THIS(" ");
		PRINT_THIS(line);
	}
	if (line)
		free(line);
	fclose(file_ptr);
	return (0);
}
