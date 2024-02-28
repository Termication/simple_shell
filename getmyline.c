#include "main.h"

/**
 * my_getline - Reads a line from a file descriptor.
 * @lineptr: Pointer to a buffer where the line will be stored.
 * @n: Pointer to the size of the buffer.
 * @fd: File descriptor to read from.
 *
 * Description:
 * - Reads a line from the file descriptor @fd into the buffer pointed to by @lineptr.
 * - The buffer size is initially set to BUFSIZE, and it grows dynamically if needed.
 * - Returns the number of characters read, or -1 on error or EOF.
 */
ssize_t my_getline(char **lineptr, size_t *n, int fd)
{
	static char buf[BUFSIZE];
	static int buf_pos = 0;  /* Current position within the buffer */
	static int buf_len = 0;  /* Number of valid bytes in the buffer */
	int bytes_read;
	char *ptr;

	if (*lineptr == NULL || *n == 0)
	{
		*n = BUFSIZE;
		*lineptr = malloc(BUFSIZE);
		if (!*lineptr)
		{
			return (-1); /* Allocation error */
		}
	}

	ptr = *lineptr;
	while (1)
	{
		if (buf_pos >= buf_len)
		{ /* Buffer is empty, read more bytes */
			buf_pos = 0;
			bytes_read = read(fd, buf, BUFSIZE);

			if (bytes_read <= 0)
			{
				if (ptr == *lineptr)
				{ /* No data was read before EOF */
					return (-1);
				}
				else
				{
					break; /* End of line reached */
				}
			}
			buf_len = bytes_read;
		}

		if (buf[buf_pos] == '\n')
		{
			buf_pos++;
			break; /* Found a newline */
		}

		*ptr++ = buf[buf_pos++];
		(*n)--;
		if (*n == 0)
		{ /* Buffer full, reallocate */
			*lineptr = realloc(*lineptr, strlen(*lineptr) + BUFSIZE);
			if (!*lineptr)
				return (-1); /* Reallocation error */
			ptr = *lineptr + strlen(*lineptr);
			*n = BUFSIZE;
		}
	}

	*ptr = '\0';
	return (ptr - *lineptr); /* Return the length of the line */
}
