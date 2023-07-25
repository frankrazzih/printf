#include "main.h"
/**
  * _printf-Prints anything to the console
  * @format: Pointer to string
  * ...: Variable number of arguments
  * Return: Number of characters printed to the console
  */
int _printf(const char *format, ...)
{
        va_list arguments;
        int cnt, i;
        char d;
        char *ptr;

        cnt = i = 0;
        va_start(arguments, format);

        while (format[i] != '\0')
        {
                if (format[i] == '%')
                {
                        switch (format[i + 1])
                        {
                                case 'c':
                                        d = va_arg(arguments, int);
                                        _putchar(d);
                                        cnt++;
                                        break;
                                case '%':
                                        _putchar('%');
                                        cnt++;
                                        break;
                                case 's':
                                        ptr = va_arg(arguments, char *);
                                        cnt += print_str(ptr);
                                        break;
                        }
                        i += 2;
                }
                else
                {
                        _putchar(format[i]);
                        i++;
                        cnt++;
                }
        }
        return (cnt);
}
