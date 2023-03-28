#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
* print_char - prints a character
* @args: the va_list that contains the character to print
*
* Return: the number of characters printed
*/
int print_char(va_list args)
{
char c = va_arg(args, int);
putchar(c);
return (1);
}

/**
* print_string - prints a string
* @args: the va_list that contains the string to print
*
* Return: the number of characters printed
*/
int print_string(va_list args)
{
char *str = va_arg(args, char *);
int len = 0;
while (*str)
{
if (*str < 32 || *str >= 127)
{
putchar('\\');
putchar('x');
printf("%02X", (unsigned char)*str);
len += 4;
}
else
{
putchar(*str);
len++;
}
str++;
}
return (len);
}

/**
* print_integer - prints an integer
* @args: the va_list that contains the integer to print
* @base: the base of the integer to print
* @uppercase: 1 if the letters in the output should be uppercase, 0 otherwise
*
* Return: the number of characters printed
*/
int print_integer(va_list args, int base, int uppercase)
{
int i;
unsigned int num;
int num_digits = 0;
char digits[32] = {'\0'};

if (base == 10)
{
int d = va_arg(args, int);
if (d < 0)
{
putchar('-');
num = (unsigned int)(-d);
num_digits++;
}
else
{
num = (unsigned int)d;
}
}
else
{
num = va_arg(args, unsigned int);
}

do {
int digit = num % base;
if (digit < 10)
{
digits[num_digits++] = digit + '0';
}
else
{
if (uppercase)
{
digits[num_digits++] = digit - 10 + 'A';
}
else
{
digits[num_digits++] = digit - 10 + 'a';
}
}
num /= base;
} while (num != 0);


for (i = num_digits - 1; i >= 0; i--)
{
putchar(digits[i]);
}

return (num_digits);
}

/**
* print_pointer - prints a pointer address
* @args: the va_list that contains the pointer to print
*
* Return: the number of characters printed
*/
int print_pointer(va_list args)
{
void *ptr = va_arg(args, void *);
printf("0x%p", ptr);
return (sizeof(void *));
}

/**
* _printf - custom printf function
* @format: the format string
* @...: additional arguments
*
* Return: the number of characters printed
*/
int _printf(const char *format, ...)
{
int num_chars = 0;
va_list args;
va_start(args, format);
if (format == NULL)
{
return (-1);
}
while (*format)
{
if (*format == '%')
{
format++;
if (*format == '\0')
{
return (-1);
}
else if (*format == '%')
{
putchar('%');
num_chars++;
}
else if (*format == 's')
{
num_chars += print_string(args);
}
else if (*format == 'c')
{
num_chars += print_char(args);
}
else if (*format == 'i' || *format == 'd')
{
num_chars += print_integer(args, 10, 0);
}
else if (*format == 'u')
{
num_chars += print_integer(args, 10, 0);
}
else if (*format == 'x')
{
num_chars += print_integer(args, 16, 0);
}
else if (*format == 'X')
{
num_chars += print_integer(args, 16, 1);
}
else if (*format == 'b')
{
num_chars += print_integer(args, 2, 0);
}
else if (*format == 'o')
{
num_chars += print_integer(args, 8, 0);
}
else if (*format == 'p')
{
num_chars += print_pointer(args);
}
else
{
putchar('%');
putchar(*format);
num_chars += 2;
}
}
else
{
putchar(*format);
num_chars++;
}
format++;
}
va_end(args);
return (num_chars);
}
