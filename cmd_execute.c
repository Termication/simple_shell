#include "main.h"

/**
 * cmd_execute - Executes a command specified by the provided command line.
 * @cmd: The command line to be executed.
 *
 * This function forks a new process and executes
 * the command specified by
 * the provided command line. It waits for
 * the child process to complete
 * execution before returning.
 */

void cmd_execute(const char *cmd)
{
	pid_t child = fork();

	if (child == -1)
	{
		handle_error("Failed to fork a new process");
		exit(EXIT_FAILURE);
	}
	else if (child == 0)
	{
		execlp(cmd, cmd, (char *)NULL);
		handle_error("Failed to fork a new process");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}
