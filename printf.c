#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _write_char - Write a character to the standard output
 * @c: The character to write
 * @count: Pointer to the character count
 */
void _write_char(char c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}

/**
 * _write_str - Write a string to the standard output
 * @str: The string to write
 * @count: Pointer to the character count
 */
void _write_str(char *str, int *count)
{
	while (*str)
	{
		_write_char(*str, count);
		str++;
	}
}

/**
 * _write_positive_int - Write a positive integer to the standard output
 * @n: The positive integer to write
 * @count: Pointer to the character count
 */
void _write_positive_int(int n, int *count)
{
	if (n == 0)
		_write_char('0', count);
	else if (n > 0)
	{
		if (n / 10)
			_write_positive_int(n / 10, count);
		_write_char(n % 10 + '0', count);
	}
}

/**
 * _write_int - Write an integer to the standard output
 * @n: The integer to write
 * @count: Pointer to the character count
 */
void _write_int(int n, int *count)
{
	if (n < 0)
	{
		_write_char('-', count);
		n = -n;
	}
	_write_positive_int(n, count);
}

/**
 * _printf - Custom printf function
 * @format: The format string
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list mylist;

	if (format == NULL)
		return (-1);

	va_start(mylist, format);

	while (*format)
	{
		if (*format != '%')
		{
			_write_char(*format, &count);
		}
		else
		{
			format++;
			if (*format == '\0')
				break;
			else if (*format == 'c')
			{
				char c = va_arg(mylist, int);
				_write_char(c, &count);
			}
			else if (*format == 's')
			{
				char *str = va_arg(mylist, char *);
				if (str == NULL)
					str = "(null)";
				_write_str(str, &count);
			}
			else if (*format == 'd' || *format == 'i')
			{
				int num = va_arg(mylist, int);
				_write_int(num, &count);
			}
			else
			{
				_write_char('%', &count);
				_write_char(*format, &count);
			}
		}
		format++;
	}

	va_end(mylist);

	return (count);
}

