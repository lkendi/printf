#include "main.h"

/**
* _printf - produces output according to a format
* @format: the format specifiers
* Return: number of printed characters excluding '\0'
*/

int _printf(const char *format, ...)
{
	int char_count = 0;

	char c, *string;

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
				case '\0':
					break;
				case '%':
					write(1, format, 1);
					char_count++;
					break;
				case 'c':
					c = va_arg(args_list, int);
					write(1, &c, 1);
					char_count++;
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
	va_end(args_list);
	return (char_count);
}

