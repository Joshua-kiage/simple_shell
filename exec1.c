#include "shell.h"
#define MAX_COMMAND_LENGTH 100
int argument_count(char *command, char *delim)
{
	int argument_index = 0;
	char *token;
	char *command_copy = _strdup(command);
	token = strtok(command_copy, delim);
	while (token != NULL)
	{
		argument_index++;
		token = strtok(NULL, delim);
	}
	free(command_copy);
	return (argument_index);
}
char **argument_array(char *command, char *delim)
{
	char *token;
	int i = 0;
	char *command_copy = _strdup(command);
	char **argument = malloc(sizeof(char *) * (argument_count(command, delim) +1));
	token = strtok(command_copy, delim);
	while (token != NULL)
	{
		argument[i] = malloc(sizeof(char) * (strlen(token) +1));
		_strcpy(argument[i], token);
		i++;
		token = strtok(NULL, delim);
	}
	argument[i] = NULL;
	free(command_copy);
	return (argument);
}
char *command_path(char *command, char *delim)
{
	char **arg = argument_array(command, delim);
	char *token, *path_copy, *cmd_path;
	char *path = getenv("PATH");
	struct stat st;
	if (path != NULL)
	{
		if (arg[0] != NULL)
		{
			path_copy = strdup(path);
			token = strtok(path_copy, ":");
			while (token != NULL)
			{
				cmd_path = (char *)malloc(sizeof(char) * (strlen(token) + strlen(arg[0]) + 2));
				_strcpy(cmd_path, token);
				_strcat(cmd_path, "/");
				_strcat(cmd_path, arg[0]);
				_strcat(cmd_path, "\0");
				if (stat(cmd_path, &st) == 0)
				{
					free(path_copy);
					free_array(arg);
					return (cmd_path);
				}
				free(cmd_path);
				token = strtok(NULL, ":");
			}
			if (stat(arg[0], &st) == 0)
			{
				cmd_path = _strdup(arg[0]);
				free(path_copy);
				free_array(arg);
				return (cmd_path);
			}
			free(path_copy);
			free_array(arg);

		}
	}
	/* free(cmd_path); */
	return (NULL);
}
/**
 * execute_command - Executes a command in a child process
 * @command: The command to be executed
 */
int execute_command(char *command, char **argument)
{
	pid_t pid;
	int status;
	pid = fork();
	if (pid < 0)
	{
		_printf("%s: No such file or directory\n", argument[0]);
		return(-1);
	}
	if (pid == 0)
	{
		if (execve(command, argument, __environ) == -1)
		{
			perror("execve: ");
			return (-1);
		}
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			status = WEXITSTATUS(status);
		if (!isatty(STDIN_FILENO))
			return (status);
	}
	return (0);
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
				_printf("%s\n", *env);
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
