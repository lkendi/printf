#include "main.h"

/**
 * print_integer - prints integers for specifier i and d
 * @char_count:num of printed chars
 * @args_list:list opf args
*/
void print_integer(int *char_count, va_list args_list)
{
    /*code*/
}

/**
* _printf - produces output according to a format
* @format: the format specifiers
* Return: number of printed characters excluding '\0'
*/
int _printf(const char *format, ...)
{
	int char_count = 0;

	char c;

	char *s;

	int d;

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
					s = va_arg(args_list, char*);
					write(1, s, strlen(s));
					char_count += strlen(s);
					break;
				case 'd':
					print_integer(&char_count, args_list);
					break;
				case 'i':
				    print_integer(&char_count, args_list);
				    break;
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

