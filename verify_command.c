#include "main.h"
/**
 * command_c - Execute a command with arguments
 * @command: The command to be executed
 * @user_input: The input string containing the command
 * @count: The count of the command
 * @arguments: The array of arguments for the command
 *
 * Return: Exit status of the command execution
 */
int command_c(char **command, char *user_input, int count, char **arguments)
{
	int status;
	pid_t child_pid;

	if (*command == NULL)
		return (EXIT_FAILURE);
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error");
		return (-1);
	}
	if (child_pid == 0)
	{
		if (_strncmp(*command, "./", 2) != 0 && _strncmp(*command, "/", 1) != 0)
			path_command(command);
		if (access(command[0], R_OK) != 0)
		{
			print_error(command[0], count, arguments);
			free_all(command, user_input);
			exit(127);
		}
		if (execve(*command, command, environ) == -1)
			return (2);
		else
			return (0);
	}
	wait(&status);
	if (WIFEXITED(status))
	{
		if (WEXITSTATUS(status) == 0)
			return (0);
		else if (WEXITSTATUS(status) == 2)
			return (2);
		else if (WEXITSTATUS(status) == 127)
			return (127);
	}
	return (127);
}
