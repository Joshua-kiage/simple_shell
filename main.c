#include "shell.h"

/**
 * main - entry point of the shell program
 * Return: As always returns 0.
 */
int main(__attribute((unused)) int ac, char **argv)
{
	char *command = NULL;
<<<<<<< HEAD
	size_t command_length = 0;
	ssize_t read = 0;
=======
	size_t command_len = 0;
	ssize_t read;
>>>>>>> 8a232ec7aeee4597bdfd42b68123132c9710a696
	int is_interactive = isatty(STDIN_FILENO);
	int command_number = 0;
	char **argument = NULL;
	char *cmd_path = NULL;
	int status = 0;

	while (1)
	{
		command_number++;
		if (is_interactive)
			_printf("($) ");

		read = getline(&command, &command_len, stdin);

		if (read == -1)
		{
			if (is_interactive)
				_printf("\n");
			free(command);
			exit(status);
		}
		if (command[read - 1] == '\n')
			command[read - 1] = '\0';
		if (_strcmp(command, "exit") == 0)
		{
			free(command);
			exit(status);
		}

		argument = argument_array((char *) command, " \n");
		cmd_path = command_path((char *) command, " \n");
		if (cmd_path != NULL)
		{
			status = execute_command(cmd_path, argument);
			free(cmd_path);
		}
		else
		{
			_print_error(argv, command_number, (char *) command);
			status = 127;
		}
		if (argument[0] != NULL)
		free_array(argument);
		command = NULL;
	}
	return (0);
}
