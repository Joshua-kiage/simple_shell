#include <unistd.h>
#include "shell.h"
/**
 * _putchar - this writes the char c to stdout
 * @c: char to be printed
 * Return: success 1.-1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
