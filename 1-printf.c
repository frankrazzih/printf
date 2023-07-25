#include "main.h"

/************************* PRINT CHAR *************************/

/**
 * print_char - Prints a char
 * @args: List a of arguments
 * @buff: Buffer array to handle print
 * @fl:  Calculates active flags
 * @w: Width
 * @prec: Precision specification
 * @sz: Size specifier
 * Return: Number of chars printed
 */
int print_char(va_list args, char buff[],
	int fl, int w, int prec, int sz)
{
	char c = va_arg(args, int);

	return (handle_write_char(c, buff, fl, w, prec, sz));
}

/************************* PRINT A STRING *************************/
/**
 * print_string - Prints a string
 * @args: List a of arguments
 * @buff: Buffer array to handle print
 * @fl:  Calculates active flags
 * @w: get width.
 * @prec: Precision specification
 * @sz: Size specifier
 * Return: Number of chars printed
 */
int print_string(va_list args, char buff[],
	int fl, int w, int prec, int sz)
{
	int length = 0, i;
	char *str = va_arg(args, char *);

	UNUSED(buff);
	UNUSED(fl);
	UNUSED(w);
	UNUSED(prec);
	UNUSED(sz);
	if (str == NULL)
	{
		str = "(null)";
		if (prec >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (prec >= 0 && prec < length)
		length = prec;

	if (w > length)
	{
		if (fl & F_MINUS)
		{
			write(1, &str[0], length);
			for (i = w - length; i > 0; i--)
				write(1, " ", 1);
			return (w);
		}
		else
		{
			for (i = w - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (w);
		}
	}

	return (write(1, str, length));
}

/************************* PRINT PERCENT SIGN *************************/
/**
 * print_percent - Prints a percent sign
 * @args: Lista of arguments
 * @buff: Buffer array to handle print
 * @fl:  Calculates active flags
 * @w: get width.
 * @prec: Precision specification
 * @sz: Size specifier
 * Return: Number of chars printed
 */
int print_percent(va_list args, char buff[],
	int fl, int w, int prec, int sz)
{
	UNUSED(args);
	UNUSED(buff);
	UNUSED(fl);
	UNUSED(w);
	UNUSED(prec);
	UNUSED(sz);
	return (write(1, "%%", 1));
}

/************************* PRINT INT *************************/
/**
 * print_int - Print int
 * @args: Lista of arguments
 * @buff: Buffer array to handle print
 * @fl:  Calculates active flags
 * @w: get width.
 * @prec: Precision specification
 * @sz: Size specifier
 * Return: Number of chars printed
 */
int print_int(va_list args, char buff[],
	int fl, int w, int prec, int sz)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(args, long int);
	unsigned long int num;

	n = convert_size_number(n, sz);

	if (n == 0)
		buff[i--] = '0';

	buff[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buff[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_number(is_negative, i, buff, fl, w, prec, sz));
}

/************************* PRINT BINARY *************************/
/**
 * print_binary - Prints an unsigned number
 * @args: Lista of arguments
 * @buff: Buffer array to handle print
 * @fl:  Calculates active flags
 * @w: get width.
 * @prec: Precision specification
 * @sz: Size specifier
 * Return: Numbers of char printed.
 */
int print_binary(va_list args, char buff[],
	int fl, int w, int prec, int sz)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(buff);
	UNUSED(fl);
	UNUSED(w);
	UNUSED(prec);
	UNUSED(sz);

	n = va_arg(args, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}

