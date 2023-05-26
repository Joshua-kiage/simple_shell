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
#include <sys/stat.h>

extern char **environ;
int _feof(FILE *file);
int execute_command(char *command, char **argument);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
char *_strcpy(char *dest, const char *src);
void _printf(const char *format, ...);
char *_strcat(char *dest, const char *src);
char *_strdup(const char *str);
int _strcmp(const char *s1, const char *s2);
int _feof(FILE *stream);
void exit_shell(void);
int _putchar(char c);
void _print_error(char **argv, int command_number, char *command);
int argument_count(char *command, char *delim);
char **argument_array(char *command, char *delim);
char *command_path(char *command, char *delim);
void free_array(char **arr);
char *integerToString(int number);
void _print_error2(char **argv, int command_number, char *command);
void exit_shell(void);

#endif
