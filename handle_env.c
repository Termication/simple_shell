#include "main.h"

/**
 * handle_env - Handles the "env" built-in command.
 * Description:
 * - Prints the environment variables to the standard output.
 */
void handle_env(void)
{
	extern char **environ;
	int i = 0;

	while (environ[i])
	{
		write(STDOUT_FILENO, environ[i], strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
