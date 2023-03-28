#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include "main.h"
/**
 * _printf - Function to _printf
 * @format: Pointer to format
 * 
 * Return: Integer, number of chars printed
 */
int _printf(const char *format, ...)
{
    int count = 0;
    char c;
    char *s;
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
                {
                    c = (char)va_arg(args, int);
                    putchar(c);
                    count++;
                    break;
                }
                case 's':
                {
                    s = va_arg(args, char *);
                    puts(s);
                    count += strlen(s);
                    break;
                }
                case '%':
                {
                    putchar('%');
                    count++;
                    break;
                }
                default:
                {
                    break;
                }
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