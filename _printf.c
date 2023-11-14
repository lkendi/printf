#include "main.h"
/**
 * print_char - prints integers for specifier c
 * @char_count:num of printed chars
 * @args_list:list of args
*/

void print_char(int *char_count, va_list args_list)
{
	char c;

	c = va_arg(args_list, int);
	write(1, &c, 1);
	(*char_count)++;
}

/**
 * print_str - prints integers for specifier s
 * @char_count:num of printed chars
 * @args_list:list of args
*/

void print_str(int *char_count, va_list args_list)
{
	char *s;

	s = va_arg(args_list, char*);
	if (s == NULL)
	{
		write(1, "(nil)", 5);
		*char_count += 5;
	}
	else
	{
		write(1, s, strlen(s));
		*char_count += strlen(s);
	}
}

/**
 * print_integer - prints integers for specifier i and d
 * @char_count:num of printed chars
 * @args_list:list opf args
*/

void print_integer(int *char_count, va_list args_list)
{
	int n, i = 0;
	int temp;
	char buffer[60];

	n = va_arg(args_list, int);
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
		(*char_count)++;
	}
	temp = n;
	if (n == 0)
	{
		buffer[i++] = '0';
	}
	else
	{
		while (temp != 0)
		{
			buffer[i++] = (temp % 10) + '0';
			temp /= 10;
		}
	}
	while (i > 0)
	{
		write(1, &buffer[--i], 1);
		(*char_count)++;
	}
}


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
