#include "shell.h"
#include <stdarg.h>

/**
 * _printf - Custom implementation of printf function
 * @format: Format string
 * 
 * Description: This function mimics the behavior of the printf function.
 * It takes a format string and variable number of arguments, and prints
 * formatted output accordingly.
 */
void _printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;

			/* Handle different format specifiers */
			switch (*format)
			{
				case 'd':
					printf("%d", va_arg(args, int));
					break;

				case 'f':
					printf("%f", va_arg(args, double));
					break;

				case 's':
					printf("%s", va_arg(args, const char *));
					break;

				default:
					putchar(*format);
					break;
			}
		}
		else
		{
			putchar(*format);
		}

		format++;
	}

	va_end(args);
}
