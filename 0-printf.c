#include "main.h"

void print_buffer(char buff[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *fmt, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (fmt == NULL)
		return (-1);

	va_start(list, fmt);

	for (i = 0; fmt && fmt[i] != '\0'; i++)
	{
		if (fmt[i] != '%')
		{
			buffer[buff_ind++] = fmt[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(fmt, &i);
			width = get_width(fmt, &i, list);
			precision = get_precision(fmt, &i, list);
			size = get_size(fmt, &i);
			++i;
			printed = handle_print(fmt, &i, list, buffer,
					flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}
	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exists
 * @buff: Array of chars
 * @buff_ind: Index at which to add the next char, represents the length.
 */
void print_buffer(char buff[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buff[0], *buff_ind);
	*buff_ind = 0;
}

