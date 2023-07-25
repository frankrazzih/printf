#include "main.h"

/************************* PRINT UNSIGNED NUMBER *************************/
/**
 * print_unsigned - Prints an unsigned number
 * @args: List a of arguments
 * @buff: Buffer array to handle print
 * @fl: Calculates active flags
 * @w: get width
 * @prec: Precision specification
 * @sz: Size specifier
 * Return: Number of chars printed.
 */
int print_unsigned(va_list args, char buff[],
	int fl, int w, int prec, int sz)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(args, unsigned long int);

	num = convert_size_unsgnd(num, sz);

	if (num == 0)
		buff[i--] = '0';

	buff[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buff[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buff, fl, w, prec, sz));
}

/************* PRINT UNSIGNED NUMBER IN OCTAL  ****************/
/**
 * print_octal - Prints an unsigned number in octal notation
 * @args: Lista of arguments
 * @buff: Buffer array to handle print
 * @fl: Calculates active flags
 * @w: get width
 * @prec: Precision specification
 * @sz: Size specifier
 * Return: Number of chars printed
 */
int print_octal(va_list args, char buff[],
	int fl, int w, int prec, int sz)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(args, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(w);

	num = convert_size_unsgnd(num, sz);

	if (num == 0)
		buff[i--] = '0';

	buff[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buff[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (fl & F_HASH && init_num != 0)
		buff[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buff, fl, w, prec, sz));
}

/************** PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/
/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @args: Lista of arguments
 * @buff: Buffer array to handle print
 * @fl: Calculates active flags
 * @w: get width
 * @prec: Precision specification
 * @sz: Size specifier
 * Return: Number of chars printed
 */
int print_hexadecimal(va_list args, char buff[],
	int fl, int w, int prec, int sz)
{
	return (print_hexa(args, "0123456789abcdef", buff,
		fl, 'x', w, prec, sz));
}

/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/
/**
 * print_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @args: Lista of arguments
 * @buff: Buffer array to handle print
 * @fl: Calculates active flags
 * @w: get width
 * @prec: Precision specification
 * @sz: Size specifier
 * Return: Number of chars printed
 */
int print_hexa_upper(va_list args, char buff[],
	int fl, int w, int prec, int sz)
{
	return (print_hexa(args, "0123456789ABCDEF", buff,
		fl, 'X', w, prec, sz));
}

/************** PRINT HEXX NUM IN LOWER OR UPPER **************/
/**
 * print_hexa - Prints a hexadecimal number in lower or upper
 * @args: Lista of arguments
 * @map_to: Array of values to map the number to
 * @buff: Buffer array to handle print
 * @fl: Calculates active flags
 * @flag_ch: Calculates active flags
 * @w: get width
 * @prec: Precision specification
 * @sz: Size specifier
 * Return: Number of chars printed
 */
int print_hexa(va_list args, char map_to[], char buff[],
	int fl, char flag_ch, int w, int prec, int sz)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(args, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(w);

	num = convert_size_unsgnd(num, sz);

	if (num == 0)
		buff[i--] = '0';

	buff[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buff[i--] = map_to[num % 16];
		num /= 16;
	}

	if (fl & F_HASH && init_num != 0)
	{
		buff[i--] = flag_ch;
		buff[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buff, fl, w, prec, sz));
}

