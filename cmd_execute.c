#include "main.h"
#define MAX_PATH_LEN 1024

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
	char *path = getenv("PATH");
	char *path_copy = strdup(path);  /*Create a copy of PATH to avoid modifying the original*/
	char *token = strtok(path_copy, ":");
	char command_with_path[MAX_PATH_LEN];

	while (token != NULL)
	{
		strcpy(command_with_path, token);
		strcat(command_with_path, "/");
		strcat(command_with_path, cmd);
		if (access(command_with_path, X_OK) == 0)  /*Check if the command exists and is executable*/
		{
			pid_t child = fork();
			if (child == -1)
			{
				perror("Failed to fork a new process");
				exit(EXIT_FAILURE);
			}
			else if (child == 0)
			{	
				char *cmd_copy = strdup(cmd);

				if (cmd_copy == NULL)
				{
					perror("Failed to duplicate command");
					exit(EXIT_FAILURE);
				}

				char *args[] = {cmd_copy, NULL};

				execve(command_with_path, args, NULL);
				perror("Failed to execute command");
				_exit(EXIT_FAILURE);
			}
			else
			{
				wait(NULL);
				free(path_copy);
				return;
			}
		}
		token = strtok(NULL, ":");
	}

/*If the loop completes without finding the command*/
	write(STDERR_FILENO, "Command not found\n", sizeof("Command not found\n") - 1);
	free(path_copy);
}
