#include <stdio.h>
#include <stdarg.h>
#include "main.h"
/**
 * _printf - Custom print function based on the format string
 * @format: The format string containing conversion specifiers
 *
 * Return: The number of characters printed (excluding the null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);
	
	int printed_chars = 0;
	
	while (*format)
	{
		if (*format != '%')
		{
			putchar(*format);
			printed_chars++;
		}
		else
		{
			format++;
			switch (*format)
			{
				case 'c':
					putchar(va_arg(args, int));
					printed_chars++;
					break;
				case 's':
					{
						const char *str = va_arg(args, const char *);
						while (*str)
						{
							putchar(*str);
							str++;
							printed_chars++;
						}
						break;
					}
				case '%':
					putchar('%');
					printed_chars++;
					break;
				default:
					break;
			}
		}
		format++;
	}
	va_end(args);
	return printed_chars;
}
