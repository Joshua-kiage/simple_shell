#include "shell.h"
/**
 * _strdup - Duplicates a string
 * @str: The string to be duplicated
 *
 * Return: On success, a pointer to the duplicated string.
 *         On failure, NULL is returned.
 */
char *_strdup(const char *str)
{
	char *duplicate;
	size_t length = strlen(str);

	duplicate = (char *)malloc((length + 1) * sizeof(char));
	if (duplicate == NULL)
	{
		fprintf(stderr, "Memory allocation failed\n");
		return (NULL);
	}

	strcpy(duplicate, str);
	return (duplicate);
}
