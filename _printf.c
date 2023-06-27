#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - function to print formatted output.
 * @format: String to be printed.
 *
 * Return: the number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;
	va_start(args, format);

	if (format == NULL)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				return (-1);

			if (*format == 'c')
			{
				int c = va_arg(args, int);
				printed_chars += _putchar(c);
			}
			else if (*format == 's')
			{
				char *str = va_arg(args, char *);
				while (*str)
				{
					printed_chars += _putchar(*str);
					str++;
				}
			}
			else if (*format == '%')
			{
				printed_chars += _putchar('%');
			}
			else
			{
				printed_chars += _putchar('%');
				printed_chars += _putchar(*format);
			}
		}
		else
		{
			printed_chars += _putchar(*format);
		}

		format++;
	}

	va_end(args);

	return (printed_chars);
}
