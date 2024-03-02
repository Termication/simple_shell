#include "main.h"

/**
 * print_error - Display error message for command not found.
 * @user_input: Input received from user
 * @loop_count: Count of shell loop
 * @program_args: Arguments before program
 * starts (program_args[0] == Shell Program Name)
 */
void print_error(char *user_input, int loop_count, char **program_args)
{
	char *error_count_str;

	PRINT_THIS(program_args[0]);
	PRINT_THIS(": ");
	error_count_str = _itoa(loop_count);
	PRINT_THIS(error_count_str);
	free(error_count_str);
	PRINT_THIS(": ");
	PRINT_THIS(user_input);
	PRINT_THIS(": command not found\n");
}

/**
 * _prerror - Print custom error message for invalid number.
 * @program_args: Arguments before program
 * starts (program_args[0] == Shell Program Name)
 * @error_count: Error count
 * @command: Array of parsed command strings
 */
void _prerror(char **program_args, int error_count, char **command)
{
	char *error_count_str = _itoa(error_count);

	PRINT_THIS(program_args[0]);
	PRINT_THIS(": ");
	PRINT_THIS(error_count_str);
	PRINT_THIS(": ");
	PRINT_THIS(command[0]);
	PRINT_THIS(": Illegal number: ");
	PRINT_THIS(command[1]);
	PRINT_THIS("\n");
	free(error_count_str);
}

/**
 * error_file - Print error message for file opening failure.
 * @program_args: Arguments before program
 * starts (program_args[0] == Shell Program Name)
 * @error_count: Error count
 */
void error_file(char **program_args, int error_count)
{
	char *error_count_str = _itoa(error_count);

	PRINT_THIS(program_args[0]);
	PRINT_THIS(": ");
	PRINT_THIS(error_count_str);
	PRINT_THIS(": Can't open ");
	PRINT_THIS(program_args[1]);
	PRINT_THIS("\n");
	free(error_count_str);
}
