#include "main.h"

/**
 * main - Entry point of the program
 * @args: Command-line arguments
 * Return: Exit status of the program
 */
int main(UNUSED int argc, char **args)
{
	char *input, **cmd, **commands;
	int cmd_count = 0, i, status = 0;

	if (args[1] != NULL)
		scan_file(args[1], args);
	signal(SIGINT, signal_handler);
	while (true)
	{
		cmd_count++;
		if (isatty(STDIN_FILENO))
			dis_prompt();
		input = custom_getline();
		if (input[0] == '\0')
			continue;
		past_arg(input);
		commands = split(input);
		for (i = 0; commands[i] != NULL; i++)
		{
			cmd = parse(commands[i]);
			if (_strcmp(cmd[0], "exit") == 0)
			{
				free(commands);
				exit_bul(cmd, input, args, cmd_count, status);
			}
			else if (check_builtin(cmd) == 0)
			{
				status = handle_builtin(cmd, status);
				free(cmd);
				continue;
			}
			else
				status = command_c(cmd, input, cmd_count, args);
			free(cmd);
		}
		free(input);
		free(commands);
		wait(&status);
	}
	return (status);
}
