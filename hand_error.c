#include "main.h"

/**
 * handle_error - Handles errors by displaying an error message.
 * @error_message: The error message to be displayed.
 */
void handle_error(const char *error_message)
{
	fprintf(stderr, "Error: %s\n", error_message);
}
