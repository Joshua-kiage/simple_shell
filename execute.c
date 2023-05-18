#include "shell.h"

#define MAX_COMMAND_LENGTH 100

/**
 * execute_command - Executes a command in a child process
 * @command: command to be executed
*/

void execute_command(const char *command)
{
	char *argument[MAX_COMMAND_LENGTH];
	char *token;
	int argument_index = 0;
	char *path = "/bin/";
	char *cmd_path;

	pid_t pid = fork();

	if (pid < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		token = strtok((char *)command, " \n");
		while (token != NULL && argument_index < MAX_COMMAND_LENGTH - 1)
		{
			argument[argument_index++] = token;
			token = strtok(NULL, " \n");
		}
		argument[argument_index] = NULL;
		cmd_path = (char *)malloc(strlen(path) + strlen(argument[0]) + 1);
		strcpy(cmd_path, path);
		strcat(cmd_path, argument[0]);

		execve(cmd_path, argument, NULL);
		perror("execve");
		free(cmd_path);
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}
