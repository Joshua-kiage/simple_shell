#include "shell.h"

/**
 * my_strcmp - Compare two strings
 * @s1: The first string to be compared
 * @s2: The second string to be compared
 *
 * Return: An integer value indicating the comparison result.
 *         0 if the strings are equal.
 *         A negative value if s1 is less than s2.
 *         A positive value if s1 is greater than s2.
 */
int _strcmp(const char *s1, const char *s2)
{
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }

    return *(unsigned char *)s1 - *(unsigned char *)s2;
}
