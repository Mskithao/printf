#include "main.h"
#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...)
{
   va_list args;
	int number = 0;
	va_start(args, format);

	while (*format)
	{
		if (*format != '%')
		{
            _putchar(*format);
			number++;
		}
		else
		{
			format++;
			if (*format == 'c')
			{
				char c = va_arg(args, int);
				_putchar(c);
				number++;
			}
			else if (*format == 's')
			{
				const char* str = va_arg(args, const char*);
                    while (*str != '\0') 
                    {
                        putchar(*str);
                        str++;
                        number++;
			        }
            }
			else if (*format == '%')
			{
				_putchar('%');
				number++;
			}
			else
			{
				_putchar('%');
				_putchar(*format);
				number += 2;
			}
		}
		format++;
	}
	va_end(args);
	return number;
}