#include "shell.h"

/**
 * _strcat - Concatenates two strings
 * @dest: The destination string
 * @src: The source string
 * Description: This function appends the content of the source string to
 * the destination string, overwriting the terminating null byte at the end
 * Return: Pointer to the destination string
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
