#include "shell_main.h"

/**
 * print_message - Prints a message to standard output.
 */

void print_message(const char *dispatch)
{
	write(STDOUT_FILENO, dispatch, strlen(dispatch));
}
