#include "shell.h"

/**
 * main - Entry point of the shell program
 *
 * Description: This function implements a simple shell program that
 * reads user commands, executes them, and provides a prompt for
 * the next command. It supports the built-in exit command to
 * terminate the shell.
 *
 * Return: Always returns 0.
 */
int main(void)
{
	char *command = NULL;
	size_t command_length = 0;
	ssize_t read;

	while (1)
	{
		_printf("($) ");
		read = getline(&command, &command_length, stdin);

		if (read == -1)
		{
			if (feof(stdin))
			{
				_printf("\n");
				exit(EXIT_SUCCESS);
			}
			_printf("Error reading command.\n");
			continue;
		}

		if (command[read - 1] == '\n')
			command[read - 1] = '\0';

		if (_strcmp(command, "exit") == 0)
		{
			free(command);
			exit(EXIT_SUCCESS);
		}

		execute_command(command);
	}

	free(command);
	return (0);
}
