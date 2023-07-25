#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include "main.h"

int _printf(const char *format, ...)
{
    if (format == NULL)
        return -1;

    char ch;
    char *str;
    size_t len, len1;
    int ret = 0;
    va_list list;
    char err[] = "Error";

    va_start(list, format);
    for (len = 0; len < strlen(format); len++)
    {
        if (format[len] != '%')
        {
            putchar(format[len]);
            ret++;
        }
        else
        {
            len++; // Move past the '%'
            if (format[len] == '\0')
                break; // Handle invalid format string ending with '%'

            switch (format[len])
            {
                case 'c':
                    ch = va_arg(list, int);
                    putchar(ch);
                    ret++;
                    break;
                case 's':
                    str = va_arg(list, char*);
                    for (len1 = 0; len1 < strlen(str); len1++)
                    {
                        putchar(str[len1]);
                        ret++;
                    }
                    break;
                default:
                    // Unsupported format specifier
                    for (len1 = 0; len1 < strlen(err); len1++)
                    {
                        putchar(err[len1]);
                    }
                    return -1;
            }
        }
    }

    va_end(list);

    return ret;
}

