#include "main.h"

/**
 * _realloc - Reallocates a memory
 * block with a new size.
 * @ptr: Pointer to the previously
 * allocated memory block.
 * @old_size: Size of the old memory block.
 * @new_size: Size of the new memory block.
 *
 * Return: Pointer to the reallocated memory block.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *result;

	if (new_size == old_size)
		return (ptr);
	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}
	result = malloc(new_size);
	if (result == NULL)
	{
		free(result);
		return (NULL);
	}
	if (ptr == NULL)
	{
		an_array(result, '\0', new_size);
		free(ptr);
	}
	else
	{
		_memcpy(result, ptr, old_size);
		free(ptr);
	}
	return (result);
}

/**
 * free_all - Frees memory allocated
 * for command array and input line.
 * @cmd: Pointer to the command array.
 * @line: Pointer to the input line.
 *
 * Description: This function frees memory
 * allocated for the command array
 * and input line, and sets the pointers to NULL.
 */
void free_all(char **cmd, char *line)
{
	free(cmd);
	free(line);
	cmd = NULL;
	line = NULL;
}

/**
 * _memcpy - Copies memory area
 * from source to destination.
 * @dest: Pointer to the destination memory area.
 * @src: Pointer to the source memory area.
 * @n: Number of bytes to copy.
 *
 * Return: Pointer to the destination memory area.
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}

/**
 * an_array - Fills memory area with a constant byte.
 * @a: Pointer to the memory area to be filled.
 * @el: Value to be set.
 * @len: Number of bytes to be set.
 *
 * Return: Pointer to the filled memory area.
 */
void an_array(void *a, int el, unsigned int len)
{
	char *p = a;
	unsigned int i = 0;

	while (i < len)
	{
		*p = el;
		p++;
		i++;
	}
	return (a);
}

/**
 * _calloc - Allocates memory for an
 * array and initializes it to zero.
 * @size: Number of elements to allocate.
 *
 * Return: Pointer to the allocated memory.
 */
void *_calloc(unsigned int size)
{
	char *a;
	unsigned int i;

	if (size == 0)
		return (NULL);
	a = malloc(size);
	if (a == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
	{
		a[i] = '\0';
	}
	return (a);
}
