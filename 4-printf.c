#include "main.h"

/**
 * get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @index: Pointer to the current index in the format string.
 * Return: Flags:
 */
int get_flags(const char *format, int *index)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int j, curr_index;
	int flags = 0;
	const char FLAGS_CHAR[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_index = *index + 1; format[curr_index] != '\0'; curr_index++)
	{
		for (j = 0; FLAGS_CHAR[j] != '\0'; j++)
		{
			if (format[curr_index] == FLAGS_CHAR[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}
		}

		if (FLAGS_CHAR[j] == '\0')
			break;
	}

	*index = curr_index - 1;

	return flags;
}

