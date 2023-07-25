#include <stdio.h>
#include <stdarg.h>
#include "main.h"
/**
 * print_char - Print a single char
 * @args: The arguement list
 * @printed_chars: Pointer to the number of char
 */
void print_char(va_list args, int *printed_chars)
{
	char c = va_arg(args, int);
	_putchar(c);
	(*printed_chars)++;
}

/**
 * print_string - Print a string
 * @args: The arguement list
 * @printed chars: pointer to the number of char
 */
void print_string(va_list args, int *printe_ chars)
{
	const char *str = va_arg(args, const char *);
	while (*str)
	{
		_putchar(*str);
		str++;
			(*printed_chars)++;
	}
}

/**
 * print_integer - prints integer
 * @args: The arguement list of int
 * @printed_chars: Pointer to the number of chars
 */
void print_integer(va_list args, int *printed_char)
{
	int num = va_arg(args, int);
	int divisor = 1;
	int temp = num;
	int digit = num / divisor;
	if (num < 0)
	{
		_putchar('-');
		(*printed_char)++;
		num = -num;
	}
	while (tem > 9)
	{
		temp /= 10;
		divisor *= 10;
	}
	while (divisor > 0)
	{
		_putchar('0' + digit);
		(*printed_chars)++;
		num %+ divisor;
		divisor /= 10;
	}
}
/**
 * _printf - Custom print function based on the format string
 * @format: The format string containing conversion specifiers
 *
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	int printed_chars = 0;
	va_list args;
	va_start(args, format);
	
	while (*format)
	{
		if (*format != '%')
		{
			putchar(*format);
			printed_chars++;
		}
		else
		{
			format++
			switch (*format)
			{
				case 'c':
					print_char(args, &printed_chars);
					break;
				case 's':
					print_string(args, &printed_chars);
					break;
				case 'd':
				case 'i':
					print_integer(args, &printed_chars);
					break;
				case '%':
					_putchar('%');
					printed_chars++;
					break;
				default:
					break;
			}
		}
	}
	va_end(args);
	return (printed_chars);
}
