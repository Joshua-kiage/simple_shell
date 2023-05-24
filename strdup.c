#include "shell.h"
/**
 * _strdup - this duplicates a string
 * @str: string to be duplicated
 *
 * Return: On success, its a pointer to the duplicated string.
 *         On failure,and NULL is returned.
 */
char *_strdup(const char *str)
{
	char *duplicate;
	size_t lngth = strlen(str);

	duplicate = (char *)malloc((lngth + 1) * sizeof(char));
	if (duplicate == NULL)
	{
		fprintf(stderr, "Memory allocation failed\n");
		return (NULL);
	}
	strcpy(duplicate, str);
	return (duplicate);
}
