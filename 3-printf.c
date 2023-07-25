#include "main.h"

/****************** PRINT POINTER ******************/
/**
 * print_pointer - Prints the value of a pointer variable
 * @args: List a of arguments
 * @buff: Buffer array to handle print
 * @fl: Calculates active flags
 * @w: get width
 * @prec: Precision specification
 * @sz: Size specifier
 * Return: Number of chars printed.
 */
int print_pointer(va_list args, char buff[],
	int fl, int w, int prec, int sz)
{
	char extra_c = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, length = 2, padd_start = 1; /* length=2, for '0x' */
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(args, void *);

	UNUSED(w);
	UNUSED(sz);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buff[BUFF_SIZE - 1] = '\0';
	UNUSED(prec);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buff[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}

	if ((fl & F_ZERO) && !(fl & F_MINUS))
		padd = '0';
	if (fl & F_PLUS)
		extra_c = '+', length++;
	else if (fl & F_SPACE)
		extra_c = ' ', length++;

	ind++;

	/*return (write(1, &buffer[i], BUFF_SIZE - i - 1));*/
	return (write_pointer(buff, ind, length,
		w, fl, padd, extra_c, padd_start));
}

/************************* PRINT NON PRINTABLE *************************/
/**
 * print_non_printable - Prints ascii codes in hexa of non printable chars
 * @args: Lista of arguments
 * @buff: Buffer array to handle print
 * @fl: Calculates active flags
 * @w: get width
 * @prec: Precision specification
 * @sz: Size specifier
 * Return: Number of chars printed
 */
int print_non_printable(va_list args, char buff[],
	int fl, int w, int prec, int sz)
{
	int i = 0, offset = 0;
	char *str = va_arg(args, char *);

	UNUSED(fl);
	UNUSED(w);
	UNUSED(prec);
	UNUSED(sz);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (is_printable(str[i]))
			buff[i + offset] = str[i];
		else
			offset += append_hexa_code(str[i], buff, i + offset);

		i++;
	}

	buff[i + offset] = '\0';

	return (write(1, buff, i + offset));
}

/************************* PRINT REVERSE *************************/
/**
 * print_reverse - Prints reverse string.
 * @args: Lista of arguments
 * @buff: Buffer array to handle print
 * @fl: Calculates active flags
 * @w: get width
 * @prec: Precision specification
 * @sz: Size specifier
 * Return: Numbers of chars printed
 */
int print_reverse(va_list args, char buff[],
	int fl, int w, int prec, int sz)
{
	char *str;
	int i, count = 0;

	UNUSED(buff);
	UNUSED(fl);
	UNUSED(w);
	UNUSED(sz);

	str = va_arg(args, char *);

	if (str == NULL)
	{
		UNUSED(prec);

		str = ")Null(";
	}
	for (i = 0; str[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		write(1, &z, 1);
		count++;
	}
	return (count);
}

/************************* PRINT A STRING IN ROT13 *************************/
/**
 * print_rot13string - Print a string in rot13.
 * @args: Lista of arguments
 * @buff: Buffer array to handle print
 * @fl: Calculates active flags
 * @w: get width
 * @prec: Precision specification
 * @sz: Size specifier
 * Return: Numbers of chars printed
 */
int print_rot13string(va_list args, char buff[],
	int fl, int w, int prec, int sz)
{
	char x;
	char *str;
	unsigned int i, j;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(args, char *);
	UNUSED(buff);
	UNUSED(fl);
	UNUSED(w);
	UNUSED(prec);
	UNUSED(sz);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				x = out[j];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[j])
		{
			x = str[i];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}

