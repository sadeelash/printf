#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

/**
 * _printf - Custom printf function
 * @format: The format string
 * @...: Variable arguments
 *
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	int firstchar = 0;
	va_list mylist;

	if (format == NULL)
		return (-1);

	va_start(mylist, format);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			firstchar++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;
			else if (*format == 'c')
			{
				char c = va_arg(mylist, int);
				write(1, &c, 1);
				firstchar++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(mylist, char *);
				int str_len = 0;

				while (str[str_len] != '\0')
					str_len++;

				write(1, str, str_len);
				firstchar += str_len;
			}
			else if (*format == '%')
			{
				write(1, format, 1);
				firstchar++;
			}
		}
		format++;
	}

	va_end(mylist);

	return firstchar;
}

