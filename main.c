#include "shell.h"

int main()
{
	char *command = NULL;
	size_t command_length = 0;
	ssize_t read;
	
	while (1)
	{
		_printf("simpleshell> ");
		read = getline(&command, &command_length, stdin);

		if (read == -1)
		{
			if (feof(stdin))
			{
				_printf("\n");  /* Print a new line after Ctrl+D */
				exit(EXIT_SUCCESS);
			}
			_printf("Error reading command.\n");
			continue;
		}

		/* Remove the newline character from the command */
		if (command[read - 1] == '\n')
			command[read - 1] = '\0';

		execute_command(command);
	}
	free(command);
	return (0);
}
