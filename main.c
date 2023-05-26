#include "shell.h"
/**
 * main - Entry point of the shell program
 * @ac: The number of command-line arguments
 * @argv: Array of command-line argument strings
 * Return: (0)
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

	if (ac > 1)
	{
		_print_error2(argv, command_number, argv[1]);
		exit(127);
	}
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
		free(command);
		command = NULL;
	}
	return (0);
}
/**
 * _print_error2 - Print error message for command open failure
 * @argv: Array of command-line arguments
 * @command_number: The number of the command being executed
 * @command: The command that failed to open
 */
void _print_error2(char **argv, int command_number, char *command)
{
	char *error_msg;
	char *str = integerToString(command_number);
	int len = strlen(argv[0]) + (2 * strlen(": ")) + strlen(command) + strlen("Can't open ") + 2;

	error_msg = (char *)malloc(sizeof(char) * len);
	if (error_msg == NULL)
	{
		fprintf(stderr, "Memory allocation error.\n");
		exit(EXIT_FAILURE);
	}
	_strcpy(error_msg, argv[0]);
	_strcat(error_msg, ": ");
	_strcat(error_msg, str);
	_strcat(error_msg, ": ");
	_strcat(error_msg, "Can't open ");
	_strcat(error_msg, command);
	_strcat(error_msg, "\n\0");
	write(STDERR_FILENO, error_msg, strlen(error_msg));
	free(error_msg);
	free(str);
}
