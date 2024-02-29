#include "main.h"

/**
 * execute_if_command_exists - Executes command
 * if it exists.
 * @args: Array of tokens representing
 * the command and its arguments.
 *
 * Description:
 * - Checks if the specified command exists.
 * - Executes it using execute function if found.
 * - Returns 1 if executed, 0 if not found.
 */
int execute_if_command_exists(char **args)
{
	if (access(args[0], F_OK) == 0)
	{
		execute(args);
		return (1); /* Executed */
	}
	else
	{
		return (0); /* Not found */
	}
}
