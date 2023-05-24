#include "shell.h"
#define MAX_COMMAND_LENGTH 100
void execute_command(const char *command)
{
	pid_t pid;
	char *argument[MAX_COMMAND_LENGTH];
	char *token, *path_copy, *cmd_path;
	int argument_index = 0;
	char *path = "/bin:/usr";

	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		char *command_copy = strdup(command);

		token = strtok(command_copy, " \n");
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
			cmd_path = (char *)malloc(strlen(token) + strlen(argument[0]) + 2);
			strcpy(cmd_path, token);
			strcat(cmd_path, "/");
			strcat(cmd_path, argument[0]);
			execve(cmd_path, argument, NULL);
			free(cmd_path);
			token = strtok(NULL, ":");
		}
		perror(argument[0]);
		free(path_copy);
		exit(EXIT_FAILURE);
	}
	else
		wait(NULL);
}

char *tokenize_string(const char *command)
{
	char *command_copy;
	char **env = environ;
	char *token;

	command_copy = strdup(command);
	token = strtok(command_copy, " \n");
	if (token != NULL && strcmp(token, "exit") == 0)
	{
		free(command_copy);
		exit_shell();
	}
	token = strtok(command_copy, " \n");
	if (token != NULL && strcmp(token, "env") == 0)
	{
		token = strtok(NULL, " \n");
		if (token == NULL)
		{
			free(command_copy);
			while (*env != NULL)
			{
				printf("%s\n", *env);
				env++;
			}
			return NULL;
		}
		free(command_copy);
	}
	return token;
}

void exit_shell(void)
{
	exit(EXIT_SUCCESS);
}
