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
	write(1, s, strlen(s));
	(*char_count)++;
}

/**
 * print_integer - prints integers for specifier i and d
 * @char_count:num of printed chars
 * @args_list:list opf args
*/

void print_integer(int *char_count, va_list args_list)
{
	int n, digits, i;
	int temp;
	char buffer[12];

	n = va_arg(args_list, int);
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
		(*char_count)++;
	}
	temp = n;
	while (temp != 0)
	{
		temp /= 10;
		digits++;
	}
	if (n == 0)
	{
		write(1, "0", 1);
		(*char_count)++;
	}
	else
	{
		for (i = 0; n != 0; i++)
		{
			buffer[i] = n % 10 + '0';
			n /= 10;
		}
		write(1, buffer, i);
		(*char_count) += i;
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
			if (format == '%')
			{
				write(1, format, 1);
				char_count++;
			}
			if (format == 'c')
			{
				print_char(&char_count, args_list);
			}
			if (format == 's')
			{
				print_str(&char_count, args_list);
			}
			if (format == 'd' || format == 'i')
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

