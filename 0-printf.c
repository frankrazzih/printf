#include "main.h"
#include <stddef.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
/**
  * _printf-Prints anything to the console
  * @format: Pointer to string
  * ...: Variable number of arguments
  * Return: Number of characters printed to the console
  */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0;
	char ch;
	char *str;
	size_t x, count = 0;

	va_start(args, format);
	count = i = 0;
	if (format == NULL)
		return (-1);
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			continue;
		}
		else
		{
			switch (format[i + 1])
			{
				case 'c':
					ch = (char) va_arg(args, int);
					_putchar(ch);
					count++;
					break;
				case 's':
					str = va_arg(args, char *);
					count += strlen(str);
					for (x = 0; x < strlen(str); x++)
					{
						_putchar(str[x]);
					}
					break;
				default:
					continue;
			}
		}
		i++;
	}
	va_end(args);
	return (count);
}
