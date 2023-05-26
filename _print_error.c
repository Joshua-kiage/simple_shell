#include "shell.h"

char* integerToString(int number)
{
	int length = snprintf(NULL, 0, "%d", number);  
	char* str = (char*)malloc(length + 1);  
	snprintf(str, length + 1, "%d", number);  
	return str;
}

void _print_error(char **argv, int command_number, char *command)
{
	char *error_msg;
	char *str = integerToString(command_number);
	int len = strlen(argv[0]) + (2 * strlen(": ")) + strlen(command) + strlen(": not found\n") + 2;
	error_msg = (char *)malloc(sizeof(char) * len);
	if (error_msg == NULL)
		exit(EXIT_FAILURE);

	_strcpy(error_msg, argv[0]);
	_strcat(error_msg, ": ");
	_strcat(error_msg, str);
	_strcat(error_msg, ": ");
	_strcat(error_msg, command);
	_strcat(error_msg, ": not found\n");
	_strcat(error_msg, "\0");
	write(STDERR_FILENO, error_msg, strlen(error_msg));
	free(error_msg);
	free(str);
}
