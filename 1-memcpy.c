#include "main.h"

/**
 * _memcpy - Copies memory area
 * @dest: Destination memory location
 * @src: Source memory location
 * @n: Number of bytes to copy
 *
 * Return: Pointer to the destination memory
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	int dest_index = 0;
	int src_index = n;

	for (; dest_index < src_index; dest_index++)
	{
		dest[dest_index] = src[dest_index];
		n--;
	}

	return (dest);
}
