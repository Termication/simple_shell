#include "main.h"

/**
 * create_path - Constructs a path
 * from a file token and value.
 * @file_token: Token representing the file.
 * @file_value: Value of the file.
 *
 * Return: Constructed path string.
 */
char *create_path(char *file_token, char *file_value)
{
	char *result;
	size_t length;

	length = _strlen(file_value) + _strlen(file_token) + 2;
	result = malloc(sizeof(char) * length);
	if (result == NULL)
	{
		free(result);
		return (NULL);
	}

	memset(result, 0, length);

	result = _strcat(result, file_value);
	result = _strcat(result, "/");
	result = _strcat(result, file_token);

	return (result);
}
/**
 * fetch_env - Retrieves the value
 * of an environment variable.
 * @var_name: Name of the variable to retrieve.
 *
 * Return: Value of the variable or
 * NULL if not found or on failure.
 */
char *fetch_env(char *var_name)
{
	size_t v_len, val_len;
	char *val;
	int i, j, k;

	v_len = _strlen(var_name);
	for (i = 0; environ[i]; i++)
	{
		if (_strncmp(var_name, environ[i], v_len) == 0)
		{
			val_len = _strlen(environ[i]) - v_len;
			val = malloc(sizeof(char) * val_len);
			if (!val)
			{
				free(val);
				perror("alloc error");
				return (NULL);
			}
			j = 0;
			for (k = v_len + 1; environ[i][k]; k++, j++)
				val[j] = environ[i][k];
			val[j] = '\0';
			return (val);
		}
	}
	return (NULL);
}

/**
 * path_command - Searches for command in
 * directories listed in PATH.
 * @command: Pointer to command to search for.
 *
 * Return: 0 on success, 1 on failure.
 *
 * Description: Searches for command in
 * PATH directories, updates pointer to
 * point to full path if found.
 */
int path_command(char **command)
{
	char *dir_path, *dir_value, *command_path;
	struct stat buffer;

	dir_path = fetch_env("PATH");
	dir_value = tokenize(dir_path, ":");

	while (dir_value != NULL)
	{
		command_path = create_path(*command, dir_value);

		if (stat(command_path, &buffer) == 0)
		{
			*command = _strdup(command_path);
			free(command_path);
			free(dir_path);
			return (0);
		}

		free(command_path);
		dir_value = tokenize(NULL, ":");
	}

	free(dir_path);
	free(dir_value);
	return (1);
}
