#ifndef MAIN_H
#define MAIN_H

int _printf(const char *format, ...);
int _putchar(char c);
void print_char(va_list args, int *printed_chars);
void print_string(va_list args, int *printed_chars);
void print_integer(va_list args, int *printed_chars);
int get_num_length(int num);
void print_number(int num);
void print_binary(unsigned int num);

#endif /* MAIN_H */
