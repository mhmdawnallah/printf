#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include "main.h"

/**
 * print_char - Function to print a character
 * @args: va_list containing the arguments
 * @count: pointer to the number of chars printed
 *
 * Return: void
 */
void print_char(va_list args, int *count)
{
char c = (char)va_arg(args, int);
putchar(c);
(*count)++;
}

/**
 * print_string - Function to print a string
 * @args: va_list containing the arguments
 * @count: pointer to the number of chars printed
 *
 * Return: void
 */
void print_string(va_list args, int *count)
{
char *s = va_arg(args, char *);
puts(s);
(*count) += strlen(s);
}

/**
 * print_integer - Function to print an integer
 * @args: va_list containing the arguments
 * @count: pointer to the number of chars printed
 *
 * Return: void
 */
void print_integer(va_list args, int *count)
{
int d = va_arg(args, int);
printf("%d", d);
(*count)++;
}

/**
 * _printf - Function to _printf
 * @format: Pointer to format
 *
 * Return: Integer, number of chars printed
 */
int _printf(const char *format, ...)
{
int count = 0;
va_list args;
va_start(args, format);
while (*format != '\0')
{
if (*format == '%')
{
format++;
switch (*format)
{
case 'c':
print_char(args, &count);
break;
case 's':
print_string(args, &count);
break;
case 'd':
case 'i':
print_integer(args, &count);
break;
case '%':
putchar('%');
count++;
break;
default:
break;
}
}
else
{
putchar(*format);
count++;
}
format++;
}

va_end(args);
return (count);
}
