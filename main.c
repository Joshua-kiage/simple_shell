#include "shell.h"
#define MAX_COMMAND_LENGTH 100

/**
 * main - Entry point for the simple_shell program.
 * Return: Always returns 0.
 */

int main(void)
{
	char command[MAX_COMMAND_LENGTH];

	while (1)
	{
		printf("simple_shell> ");

		if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
		{
			printf("\n");
			break;
		}
		command[strcspn(command, "\n")] = '\0';
		execute_command(command);
	}
	return (0);
}
