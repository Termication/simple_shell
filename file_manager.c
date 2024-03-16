#include "main.h"

/**
 * closing_built - Clean up & exit based on
 * built-in command & status code.
 * @commands: Array of command strings.
 * @input_line: Pointer to the input line.
 * @file_descriptor: Pointer to the file descriptor.
 */
void closing_built(char **commands, char *input_line, FILE *file_descriptor)
{
	int exit_status;
	int index = 0;

	if (commands[index] == NULL)
	{
		free(input_line);
		free(commands);
		fclose(file_descriptor);
		exit(errno);
	}
	while (commands[1][index])
	{
		if (_isalpha(commands[1][index++]) < 0)
			perror("Illegal number");
	}
	exit_status = _atoi(commands[1]);
	free(input_line);
	free(commands);
	fclose(file_descriptor);
	exit(exit_status);
}
/*
 * scan_file - Reads lines from a file and
 * processes them using the provided arguments.
 * If the file cannot be opened, it
 * handles the error and exits with status 127.
 *
 * file_name: The name of the file to read.
 * arguments: The arguments to be
 * passed for processing each line.
 */
void scan_file(char *file_name, char **arguments)
{
	FILE *file_ptr;
	char *line = NULL;
	size_t line_length = 0;
	int counter = 0;

	file_ptr = fopen(file_name, "r");
	if (file_ptr == NULL)
	{
		error_file(arguments, counter);
		exit(127);
	}
	while ((getline(&line, &line_length, file_ptr)) != -1)
	{
		counter++;
		file_exa(line, counter, file_ptr, arguments);
	}
	if (line)
		free(line);
	fclose(file_ptr);
	exit(0);
}
/**
 * file_exa - Examines and processes lines from a file.
 * @file_line: Line read from file.
 * @line_count: Line number being processed.
 * @file_ptr: Pointer to file.
 * @arguments: Command-line args.
 *
 * Description: Examines and processes
 * each line from a file, parsing into
 * command and arguments,
 */
void file_exa(char *file_line, int line_count,
		FILE *file_ptr, char **arguments)
{
	char **command;
	int status = 0;

	command = parse(file_line);
	if (_strncmp(command[0], "exit", 4) == 0)
		closing_built(command, file_line, file_ptr);
	else if (check_builtin(command) == 0)
	{
		status = handle_builtin(command, status);
		free(command);
	}
	else
	{
		status = command_c(command, file_line, line_count, arguments);
		free(command);
	}
}
