#include "main.h"
/**
 * print_digit - Prints a single digit
 * @number: The digit to print
 *
 * Description: Prints a single digit, accounting for negative numbers.
 */
void print_digit(int number)
{
	unsigned int temp = number;

	if (number < 0)
	{
		_putchar('-');
		temp = -temp;
	}
	if ((temp / 10) > 0)
		dis_num(temp / 10);

	_putchar(temp % 10 + '0');
}

/**
 * echoing - Executes the echo command with given arguments.
 * @arguments: Array of strings representing the command and its arguments.
 *
 * Return: 1 if execution succeeds, -1 if error occurs.
 */
int echoing(char **arguments)
{
	pid_t child_pid;
	int exit_status;

	/* Fork a child process */
	child_pid = fork();
	if (child_pid == 0)
	{
		/* Execute the echo command */
		if (execve("/bin/echo", arguments, environ) == -1)
		{
			return (-1);
		}
		exit(EXIT_FAILURE);
	}
	else if (child_pid < 0)
	{
		return (-1);
	}
	else
	{
		/* Wait for the child process to complete */
		do {
			waitpid(child_pid, &exit_status, WUNTRACED);
		} while (!WIFEXITED(exit_status) && !WIFSIGNALED(exit_status));
	}
	return (1);
}

code
/**
 * dis_num - Prints an unsigned integer recursively
 * @number: The unsigned integer to print
 */
void dis_num(unsigned int number)
{
	unsigned int temp = number;

	if ((temp / 10) > 0)
		dis_num(temp / 10);

	_putchar(temp % 10 + '0');
}
