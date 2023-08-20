#include "main.h"

/**
 * _printf - formatting function that is used to print a string to stdout.
 * @format: the string and the format of the output.
 *
 * Return: the number of printed characters, negative value on falure.
 **/
int _printf(const char *format, ...)
{
	unsigned int i, len = 0;
	va_list args;
	int (*func)(va_list);

	if (!check_format(format))
		return (-1);
	va_start(args, format);

	for (i = 0; format[i]; i++)
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			len++;
		}
		else
		{
			i++;
			if (format[i] == '%')
			{
				write(1, "%", 1);
				len++;
			}
			else if (get_func(format[i]))
			{
				func = get_func(format[i]);
				len += func(args);
			}
		}
	}
	va_end(args);
	return (len);
}
