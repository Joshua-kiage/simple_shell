#include "shell.h"
/**
 * _strcmp - this will compare two strings
 * @s1: first string
 * @s2: second string
 * Return: An integer value indicating of the comparison result.
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
