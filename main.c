#include "main.h"
/**
 * main - function of the simple shell.
 * 
 * Description:
 * - Continuously prompts the user with a shell prompt.
 * - Reads input from the user.
 * - Handles Ctrl-D to exit the shell.
 * - Splits the input line into individual arguments.
 * - Checks for and handles built-in commands.
 * - Executes the command if it exists in the system.
 * - Prints an error message if the command is not found.
 * - Frees allocated memory before exiting.
 * 
 * Return:
 * - Returns 0 upon successful execution.
 */

int main(void)
{
	char *line, **args;
	char prompt[] = "$ ";
	int prompt_len = strlen(prompt);

	while (1)
	{
		/* Print the shell prompt */
		write(STDOUT_FILENO, prompt, prompt_len);

		/* Read input from the user */
		line = read_line();

		/* Handle Ctrl-D */
		if (line == NULL)
		{
			break;
		}

		/* Split the input line into individual arguments */
		args = split_line(line);

		/* Check for and handle built-in commands */
		if (!handle_builtin_commands(args))
		{
			/* New function to handle execution */
			if (!execute_if_command_exists(args))
			{
				/* Command not found */
				write(STDERR_FILENO, "simple_shell: command not found\n", 32);
			}
		}

		/* Free allocated memory */
		free(line);
		free(args);
	}

	return (0);
}
