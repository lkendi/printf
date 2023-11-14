#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: the format specifiers
 * Return: number of printed characters excluding \0
 */

int _printf(const char *format, ...)
{
	int char_count = 0;
	va_list args_list;

	if (format == NULL)
	{
		exit(1);
	}

	va_start(args_list, format);
	switch (*format)
	{
		case '%':
			format++;
			switch (*format)
			{
				case '%':
					/*code*/
					break;
				case 'c':
					/*code*/
					break;
				case 's':
					/*code*/
					break;
			}
		break;
	default:
		write(1, format, 1);
		char_count++;
		break;
	}
	return(char_count);
}

