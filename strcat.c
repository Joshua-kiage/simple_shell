#include "shell.h"
/**
 * _strcat - it oncatenates the two strings
 * @dest: The destination string
 * @src: source string
 * Return: Pointer that points to the destination string
 */
char *_strcat(char *dest, const char *src)
{
	char *dest_ptr = dest;
	/* Move the pointer to the end of the destination string */
	while (*dest_ptr != '\0')
		dest_ptr++;
	/* Append the source string to the destination string */
	while (*src != '\0')
		*dest_ptr++ = *src++;
	/* Add the terminating null byte */
	*dest_ptr = '\0';
	return (dest);
}
