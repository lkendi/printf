#include "main.h"
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
					/*code*/
					break;
				case 'i':
				    d = va_arg(args_list, int);
				    write(1, &d, sizeof(int));
				    char_count += sizeof(int);
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

