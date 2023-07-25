#include "main.h"
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdarg.h>

/**
 * _printf - prints strings and chars
 * @format - string containing the format specifiers
 * Return: the number of chars printed
 */
int _printf(const char *format, ...)
{
        char *ch;
        char *str;
        size_t len;
        int ret = 0;
        va_list list;

        va_start(list, format);
        for (len = 0; len < strlen(format); len ++)
        {
                if (format[len] == '%' && format[len + 1] == 'c')
                {
                        ch = va_arg(list, char*);
                        printf("%c", ch);
                        ret += strlen(ch);
                }
                else if (format[len] == '%' && format[len + 1] == 's')
                {
                        str = va_arg(list, char*);
                        printf("%s", str);
                        ret += strlen(str);
                }
        }
        return (ret);
}
