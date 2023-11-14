#include "main.h"

/**
* _printf - produces output according to a format
* @format: the format specifiers
* Return: number of printed characters excluding '\0'
*/

int _printf(const char *format, ...)
{
	int char_count = 0;
	va_list args_list;

	if (format == NULL)
	{
		return (-1);
	}
	va_start(args_list, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
			{
				write(1, format, 1);
				char_count++;
			}
			if (*format == 'c')
			{
				print_char(&char_count, args_list);
			}
			if (*format == 's')
			{
				print_str(&char_count, args_list);
			}
			if (*format == 'd' || *format == 'i')
			{
				print_integer(&char_count, args_list);
			}
		}
		else
		{
			write(1, format, 1);
			char_count++;
		}
		format++;
	}
	va_end(args_list);
	return (char_count);
}

