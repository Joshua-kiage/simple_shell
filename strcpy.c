#include "shell.h"
/**
 * _strcpy - it copies the string pointed to by src
 * @dest: pointer to the destination buffe
 * @src:  pointer to the source string to be copied
 * Return: a pointer to the destination string dest
 */
char *_strcpy(char *dest, const char *src)
{
	int idx = 0;

	while (src[idx] != '\0')
	{
		dest[idx] = src[idx];
		idx++;
	}
	dest[idx] = '\0';
	return (dest);
}
