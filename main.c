#include "shell_main.h"	/* Include the shell header file */

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

		/* Read command from user */
		fgets(cmd, sizeof(cmd), stdin);
		/* Here you would execute the command entered by the user */
	}

	return (0);
}
