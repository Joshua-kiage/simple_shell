#include "shell.h"
int main(void)
{
	char *command = NULL;
	size_t command_length = 0;
	ssize_t read;
	int is_interactive = isatty(STDIN_FILENO);

	while (1)
	{
		if (is_interactive)
			printf("($) ");

		read = getline(&command, &command_length, stdin);

		if (read == -1)
		{
			if (feof(stdin))
			{
				if (is_interactive)
					printf("\n");
				exit(EXIT_SUCCESS);
			}
			printf("Error reading command.\n");
			continue;
		}

		if (command[read - 1] == '\n')
			command[read - 1] = '\0';

		if (strcmp(command, "exit") == 0)
		{
			free(command);
			exit(EXIT_SUCCESS);
		}

		execute_command(command);
	}

	free(command);
	return (0);
}
