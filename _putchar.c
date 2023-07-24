#include <stdarg.h>
#include "main.h"
/**
 * _putchar - Custom function to print a single character to stdout
 * @c: The character to be printed
 *
 * Return: On success, returns the character printed as an unsigned char.
 * On failure, returns EOF.
 */
int _putchar(char c)
{
	return write(1, &c, 1);
}
