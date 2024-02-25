#include "shell_main.h"

/**
 * print_message - Prints a message to standard output
 * @dispatch: The message to be printed.
 */

void print_message(const char *dispatch)
{
	write(STDOUT_FILENO, dispatch, strlen(dispatch));
}
