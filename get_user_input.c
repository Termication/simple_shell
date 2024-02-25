#include "main.h"
/**
 * get_user_input - Reads input from the user and removes trailing newline.
 * @cmd: Buffer to store the input command.
 * @size: Size of the buffer.
 */

void get_user_input(char *cmd, size_t size)
{
	if (fgets(cmd, size, stdin) == NULL)
	{
		if (feof(stdin))
		{
			print_message("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			print_message("ERROR: Failed to read input command\n");
			exit(EXIT_FAILURE);
		}
	}

	cmd[strcspn(cmd, "\n")] = '\0';

}
