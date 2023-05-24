#include <stdio.h>
#include "shell.h"

/**
 * _feof - Custom implementation of feof function.
 * @file: Pointer to the file.
 *
 * Return: 1 if EOF reached, 0 otherwise.
 */

int _feof(FILE *file)
{
	long currentPos;
	long endPos;

	if (file == NULL)
		return (-1);

	currentPos = ftell(file);
	if (currentPos == -1)
		return (-1);

	if (fseek(file, 0, SEEK_END) == -1)
		return (-1);

	endPos = ftell(file);
	if (endPos == -1)
		return (-1);

	if (fseek(file, currentPos, SEEK_SET) == -1)
		return (-1);

	return (currentPos == endPos);
}
