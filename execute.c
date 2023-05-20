#include "shell.h"

#define MAX_COMMAND_LENGTH 100

/**
 * execute_command - Executes a command in a child process
 * @command: command to be executed
*/

void execute_command(const char *command)
{
	char *argument[MAX_COMMAND_LENGTH], *token;
	int argument_index = 0;
	char *path = "/bin:/usr";
	char *cmd_path;
	char *path_copy;

	pid_t pid = fork();

	if (pid < 0)
	{
		printf("%s: No such file or directory\n", argument[0]);
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		char command_copy[MAX_COMMAND_LENGTH];

		strncpy(command_copy, command, sizeof(command_copy));
		token = strtok((char *)command, " \n");

		while (token != NULL && argument_index < MAX_COMMAND_LENGTH - 1)
		{
			argument[argument_index++] = token;
			token = strtok(NULL, " \n");
		}
		argument[argument_index] = NULL;

		path_copy = strdup(path);

		token = strtok(path_copy, ":");

		while (token != NULL)
		{
			cmd_path = (char *)malloc(strlen(path) + strlen(argument[0]) + 2);
			strcpy(cmd_path, token);
			strcat(cmd_path, "/");
			strcat(cmd_path, argument[0]);
			execve(cmd_path, argument, NULL);
			free(cmd_path);
			token = strtok(NULL, ":");
		}
		printf("%s: No such file or directory\n", argument[0]);
		free(path_copy);
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}
