#include "main.h"

/**
* find_command_in_path - Finds the full path of
* a command in the PATH environment variable.
* @command: The command to search for.
*
* Return: The full path of the command
* if found, or NULL if not found.
*/
char *find_command_in_path(char *command)
{
	char *path_env = getenv("PATH");
	char *path_copy = strdup(path_env);
	char *full_path = NULL;
	char *dir;

	dir = strtok(path_copy, ":");
	while (dir != NULL)
	{
		full_path = malloc(strlen(dir) + strlen(command) + 2);
		strcpy(full_path, dir);
		strcat(full_path, "/");
		strcat(full_path, command); /* Using command here */

		if (access(full_path, F_OK) == 0)
		{
			return (full_path);
		}

		free(full_path);
		full_path = NULL;
		dir = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL); /* Command not found in any PATH directory */
}
