#include <stdarg.h>
#include <unistd.h>
#include "main.h"
/**
 * _printf - Custom print function based on the format string
 * @format: The format string containing conversion specifiers
 *
 * Return: The number of characters printed (excluding the null byte used to end output to strings)
 */
int get_num_length(int num);
void print_number(int num);

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
int get_num_length(int num)
{
	int length = 0;
	if (num == 0)
	{
		return 1;
	}
	while (num > 0)
	{
		num /= 10;
		length++;
	}
	return length;
}

void print_number(int num)
{
	int reversed = 0;
	if (num == 0)
	{
		_putchar('0');
		return;
	}
	while (num > 0)
	{
		reversed = reversed * 10 + num % 10;
		num /= 10;
	}
	while (reversed > 0)
	{
		_putchar(reversed % 10 + '0');
		reversed /= 10;
	}
}
