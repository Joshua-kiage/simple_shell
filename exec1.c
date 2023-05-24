#include "shell.h"
#define MAX_COMMAND_LENGTH 100
/**
 * execute_command - Executes a command in a child process
 * @command: The command to be executed
 */
void execute_command(const char *command)
{
	pid_t pid;
	char *argument[MAX_COMMAND_LENGTH], *token, *path_copy, *cmd_path;
	int argument_index = 0;
	char *path = "/bin:/usr";

	pid = fork();
	if (pid < 0)
	{
		_printf("%s: No such file or directory\n", argument[0]);
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		char *command_copy = _strdup(command);

		token = strtok(command_copy, " \n");
		while (token != NULL && argument_index < MAX_COMMAND_LENGTH - 1)
		{
			argument[argument_index++] = token;
			token = strtok(NULL, " \n");
		}
		argument[argument_index] = NULL;
		path_copy = _strdup(path);
		token = strtok(path_copy, ":");
		while (token != NULL)
		{
			cmd_path = (char *)malloc(strlen(path) + strlen(argument[0]) + 2);
			_strcpy(cmd_path, token);
			_strcat(cmd_path, "/");
			_strcat(cmd_path, argument[0]);
			execve(cmd_path, argument, NULL);
			free(cmd_path);
			token = strtok(NULL, ":");
		}
		_printf("%s: No such file or directory\n", argument[0]);
		free(path_copy);
		exit(EXIT_FAILURE);
	}
	else
		wait(NULL);
}
/**
 * tokenize_string - Tokenizes a string into an array of tokens
 * @command: The pointer to be tokenized
 * Return: The first token found or NULL if no token is found
 */
char *tokenize_string(const char *command)
{
	char *command_copy;
	char **env = environ;
	char *token;

	command_copy = _strdup(command);  /* Create a non-constant copy */
	token = strtok(command_copy, " \n");
	if (token != NULL && _strcmp(token, "exit") == 0)
	{
		free(command_copy);  /* Free the copied string before exit */
		exit_shell();
	}
	/* Check if the command is "env" and print the environment variables */
	token = strtok(command_copy, " \n");
	if (token != NULL && _strcmp(token, "env") == 0)
	{
		token = strtok(NULL, " \n");  /* Move to the next token */
		if (token == NULL)
		{
			free(command_copy);  /* Free the copied string before returning */
			while (*env != NULL)
			{
				printf("%s\n", *env);
				env++;
			}
			return (NULL);
		}
		free(command_copy);  /* Free the copied string before further processing */
	}
	return (token);
}
/**
 * exit_shell - this will exits the shell
 */
void exit_shell(void)
{
	exit(EXIT_SUCCESS);
}
