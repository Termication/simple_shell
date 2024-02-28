#include "main.h"

/**
* execute - Executes the given command.
* @args: An array of tokens representing the command and its arguments.
* Return: 0 on success, or -1 on error.
*/
int execute(char **args)
{
	pid_t pid;
	int status;

	if (access(args[0], F_OK) != 0)
	{
		return (-1);
	}

	pid = fork();
	if (pid == 0)
	{
		/* Child process */
		if (execvp(args[0], args) == -1)
		{
			perror("Execution error");
		}
		_exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		/* Error forking */
		perror("Fork error");
	}
	else
	{
		/* Parent process */
		waitpid(pid, &status, 0);
	}

	return (0);
}
