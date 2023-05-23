#include "shell.h"
#define BUFFER_SIZE 1024
/**
 * _getline - customized getline function
 * @lineptr: the pointer to the buffer storing the line
 * @n: the pointer to the size of the buffer
 * @stream: the file stream to read from
 * Description of what it does:
 * 1. It reads a line from the provided file stream and stores it in lineptr.
 * 2. buffer is dynamically resized as needed to accommodate the line.
 * 3. returns the number of characters read (including newline character),
 */

ssize_t _getline(char **lineptr, size_t *n, FILE *stream);


ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	static char buff[BUFFER_SIZE];
	static size_t buff_idx = 0;
	static ssize_t buff_siz = 0;

	size_t line_length = 0;
	char *line = NULL;
	int newline_found = 0;
	char current_char;

	if (lineptr == NULL || n == NULL)
	{
		errno = EINVAL;
		return -1;
	}

	if ((size_t)buff_idx >= (size_t)buff_siz)
	{
		buff_siz = read(fileno(stream), buff, BUFFER_SIZE);
		buff_idx = 0;

		if (buff_siz <= 0)
		{
			/* No more data to read or an error occurred */
			return buff_siz;
		}
	}

	while ((size_t)buff_idx < (size_t)buff_siz)
	{
		if (line_length + 1 >= *n)
		{
			char *new_line ;

			/* Extend the line buffer */
			*n *= 2;
			new_line = realloc(line, *n);

			if (new_line == NULL)
			{
				free(line);
				return -1;
			}

			line = new_line;
		}

		current_char = buff[buff_idx++];
		line[line_length++] = current_char;

		if (current_char == '\n')
		{
			newline_found = 1;
			break;
		}
	}

	line[line_length] = '\0';
	*lineptr = line;

	if (newline_found)
	{
		return line_length;
	}
	else
	{
		return -1;
	}
}

