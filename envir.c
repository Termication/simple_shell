#include "main.h"

/**
 * create_envi - Copies environment variables.
 * @envi: Pointer to store environment variables.
 */
void create_envi(char **envi)
{
	for (int i = 0; environ[i]; i++)
	envi[i] = _strdup(environ[i]);
	envi[i] = NULL;
}

/**
 * free_env - Frees environment variables.
 * @env: Pointer to environment variables.
 */
void free_env(char **env)
{
	for (int i = 0; env[i]; i++)
	free(env[i]);
}

