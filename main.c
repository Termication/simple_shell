#include "main.h"

/**
 * main - Entry point of the program
 *
 * Return: Always 0
 */
int main(void)
{
	char cmd[100];	/* Buffer to store user input */

	/* Infinite loop to continuously prompt for input */
	while (1)
	{
		/* Print shell prompt */
		dis_prompt();
		get_user_input(cmd, sizeof(cmd));
		cmd_execute(cmd);
	}

	return (0);
}
