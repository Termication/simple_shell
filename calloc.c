#include "main.h"
#include <stdlib.h>

/**
* _calloc - allocates memory for an array of @nmemb elements of
* @size bytes each and returns a pointer to the allocated memory.
*
* @nmemb: number of elements in the array
* @size: size of each element in bytes
*
* Return: pointer to the allocated memory.
*/
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *allocated_memory;
	unsigned int index;

	if (nmemb == 0 || size == 0)
		return (NULL);

	allocated_memory = malloc(nmemb * size);

	if (allocated_memory == NULL)
		return (NULL);

	for (index = 0; index < (nmemb * size); index++)
		allocated_memory[index] = 0;

	return (allocated_memory);
}
