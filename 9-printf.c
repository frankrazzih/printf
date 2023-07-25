#include "main.h"

/**
 * is_printable - Evaluates if a char is printable
 * @ch: Char to be evaluated.
 *
 * Return: 1 if ch is printable, 0 otherwise
 */
int is_printable(char ch)
{
	if (ch >= 32 && ch < 127)
		return 1;

	return 0;
}

/**
 * append_hexa_code - Append ASCII in hexadecimal code to buffer
 * @buffer: Array of chars.
 * @index: Index at which to start appending.
 * @ascii_code: ASCII CODE.
 * Return: Always 3
 */
int append_hexa_code(char ascii_code, char buffer[], int index)
{
	char map_to[] = "0123456789ABCDEF";
	/* The hexadecimal format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[index++] = '\\';
	buffer[index++] = 'x';

	buffer[index++] = map_to[ascii_code / 16];
	buffer[index] = map_to[ascii_code % 16];

	return 3;
}

/**
 * is_digit - Verifies if a char is a digit
 * @ch: Char to be evaluated
 *
 * Return: 1 if ch is a digit, 0 otherwise
 */
int is_digit(char ch)
{
	if (ch >= '0' && ch <= '9')
		return 1;

	return 0;
}

/**
 * convert_size_number - Casts a number to the specified size
 * @num: Number to be casted.
 * @size: Number indicating the type to be casted.
 *
 * Return: Casted value of num
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return num;
	else if (size == S_SHORT)
		return (short)num;

	return (int)num;
}

/**
 * convert_size_unsgnd - Casts a number to the specified size
 * @num: Number to be casted
 * @size: Number indicating the type to be casted
 *
 * Return: Casted value of num
 */
unsigned long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return num;
	else if (size == S_SHORT)
		return (unsigned short)num;

	return (unsigned int)num;
}

