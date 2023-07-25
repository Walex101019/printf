#ifndef MAIN_H
#define MAIN_H

int _printf(const char *format, ...);
int _putchar(char c);
void print_char(va_list args, int *printed_chars);
void print_string(va_list args, int *printed_chars);
void print_integer(va_list args, int *printed_chars);

#endif /* MAIN_H */
