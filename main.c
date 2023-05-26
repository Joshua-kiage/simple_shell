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
int main(__attribute((unused)) int ac, char **argv)
{
	char *command = NULL;
	size_t command_length = 0;
	ssize_t read = 0;
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

		read = getline(&command, &command_length, stdin);

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
