#include "shell.h"

/**
 * _strtok - Custom strtok-like function
 * @str: The string to tokenize
 * @delim: The delimiter used to separate tokens
 * Return: A pointer to the next token, or NULL if no more tokens
 */
char *_strtok(char *str, const char *delim)
{
        static char *last_token = NULL;
        char *token;

        if (str != NULL)
                last_token = str;

        if (last_token == NULL || *last_token == '\0')
                return (NULL);

        token = last_token;
        while (*last_token != '\0')
        {
                if (*last_token == *delim)
                {
                        *last_token = '\0';
                        last_token++;
                        return (token);
                }
                last_token++;
        }

        return (token);
}

