#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stddef.h>
#include "main.h"

/**
 * _printf - prints to the std output depending
 *on the specifier fiven as argument
 * @format : string containing the format specifiers
 * Return: strlen of whatever is printed
 */
int _printf(const char *format, ...)
{
	char ch;
	char *str;
	size_t len, len1;
	int ret = 0;
	va_list list;
	char err[] = "Error";


	va_start(list, format);
	for (len = 0; len < strlen(format); len += 2)
	{
		if (format == NULL || format[len] != '%')
		{
			for (len1 = 0; len1 < strlen(err); len1++)
			{
				putchar(err[ret]);
			}
			return (-1);
		}
		if (format[len] == '%' && format[len + 1] == 'c')
		{
			ch = va_arg(list, int);
			putchar("%c", ch);
			ret += 1;
		}
		else if (format[len] == '%' && format[len + 1] == 's')
		{
			str = va_arg(list, char*);
			for (len1 = 0; len1 < strlen(str); len1++)
			{
				putchar(str[len1]);
			}
			ret += strlen(str);
		}
	}
	return (ret);
}
