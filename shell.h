#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stddef.h>
#include <string.h>
#include <errno.h>

extern char **environ;


void execute_command(const char *command);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
char *_strcpy(char *dest, const char *src);
void _printf(const char *format, ...);
char *_strcat(char *dest, const char *src);
char *_strdup(const char *str);
int _strcmp(const char *s1, const char *s2);
int _feof(FILE *stream);
void exit_shell(void);


#endif
