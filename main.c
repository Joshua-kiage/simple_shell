#include "shell.h"

/**
 * main - entry point of the shell program
 * Return: As always returns 0.
 */
int main(void)
{
	char *command = NULL;
	size_t command_len = 0;
	ssize_t read;
	int is_interactive = isatty(STDIN_FILENO);

	while (1)
	{
		if (is_interactive)
			_printf("($) ");

		read = getline(&command, &command_len, stdin);

		if (read == -1)
		{
			if (_feof(stdin))
			{
				if (is_interactive)
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
