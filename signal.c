#include "main.h"

/**
 * signal_handler - Handles signals, specifically SIGINT
 * @signal: The signal to handle
 *
 * Description: Handles SIGINT signal by printing a new prompt.
 */
void signal_handler(int signal)
{
	if (signal == SIGINT)
	{
		PRINT_THIS("\n$ ");
	}
}
