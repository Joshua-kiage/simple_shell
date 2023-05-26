#include "shell.h"
#define BUFFER_SIZE 128

/**
 * _getline - Reads a line from a stream and dynamically allocates memory for it.
 *
 * @lineptr: Pointer to the buffer where the line will be stored.
 * @n: Pointer to the initial size of the buffer.
 * @stream: The input stream to read from.
 *
 * Return: The number of characters read, excluding the newline character ('\n'),
 *         or -1 if an error occurs or if the end-of-file is reached.
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
    ssize_t read_chars = 0;
    int curr_char;
    static char buffer[BUFFER_SIZE];
    static size_t buffer_index = 0; 

    if (lineptr == NULL || n == NULL || stream == NULL)
        return -1;

    /* Allocate initial buffer if lineptr is NULL or buffer size is 0 */
    if (*lineptr == NULL || *n == 0)
    {
        *n = BUFFER_SIZE;
        *lineptr = malloc(*n);
        if (*lineptr == NULL)
            return -1; /* Memory allocation failure */
    }

    while (1)
    {
        /* Refill buffer if necessary */
        if (buffer_index == 0)
        {
            read_chars = fread(buffer, sizeof(char), BUFFER_SIZE, stream);
            if (read_chars == 0)
                return -1; /* No characters read or end-of-file reached */
        }

        curr_char = buffer[buffer_index++];
        (*lineptr)[read_chars] = (char) curr_char;
        read_chars++;

        /* Expand buffer if necessary */
        if (read_chars >= *n - 1)
        {
            size_t buffer_size = *n * 2; /* Double the buffer size */
            char *new_lineptr = realloc(*lineptr, buffer_size);
            if (new_lineptr == NULL)
                return -1; /* Memory allocation failure */
            *lineptr = new_lineptr;
            *n = buffer_size;
        }

        if (curr_char == '\n')
            break;
    }

    (*lineptr)[read_chars] = '\0'; /* Null-terminate the line */
    return read_chars;
}

