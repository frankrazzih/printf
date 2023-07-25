#include "main.h"
#include <unistd.h>
/**
  * _putchar-prints a character to the console
  * @c: the character to print
  *
  * Return: an integer
  */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
