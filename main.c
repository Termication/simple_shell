#include "main.h"
#define MAX_ARGS 11

/**
 * main - Entry point of the program
 *
 * Return: Always 0
 */
int main(void)
{
	char cmd[100];	/* Buffer to store user input */
	char *args[MAX_ARGS];
	int num_args;

	/* Infinite loop to continuously prompt for input */
	while (1)
	{
		/* Print shell prompt */
		dis_prompt();
		get_user_input(cmd, sizeof(cmd));
		cmd_execute(cmd);

		num_args = tokenize_command(cmd, args);
		for (int i = 0; i < num_args; i++)
		{
			
			cmd_execute(args[i]);
		}
	}

	return (0);
}
