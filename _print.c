#include <stdarg.h>
#include <unistd.h>
#include "main.h"

int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	
	va_start(args, format);
	
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					{
						char c = va_arg(args, int);
						_putchar(c);
						count++;
						break;
					}
				case 's':
					{
						const char *s = va_arg(args, char *);
						while (*s)
						{
							_putchar(*s);
							s++;
							count++;
						}
						break;
					}
				case 'd':
				case 'i':
					{
						int num = va_arg(args, int);
						if (num < 0)
						{
							_putchar('-');
							count++;
							num = -num;
						}
						print_number(num);
						count += get_num_length(num);
						break;
					}
				case '%':
					_putchar('%');
					count++;
					break;
				default:
					_putchar(*format);
					count++;
					break;
			}
		}
		else
		{
			_putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
