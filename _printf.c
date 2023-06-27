#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - function to print string to standard output.
 * @format: String to be printed.
 * Return: number of characters printed.
*/


int _printf(const char *format, ...)
{
va_list args;
va_start(args, format);

while (*format)
{
if (*format != '%')
{
_putchar(*format);
format++;
}
else
{
format++;
if (*format == 'c')
{
char c = va_arg(args, int);
_putchar(c);
format++;
}
else if (*format == 's')
{
const char *str = va_arg(args, const char*);
while (*str != '\0')
{
putchar(*str);
str++;
}
}
else if (*format == '%')
{
_putchar('%');
format++;
}
else
{
_putchar('%');
_putchar(*format);
format++;
}
}
format++;
}
va_end(args);
return (1);
}
