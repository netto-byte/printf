#include "main.h"

/**
 * _printf - Prints a format string
 * @format: Format string
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list a_ptr;
	char buffer[BUF_SIZE];
	int i = 0, char_count = 0, buf_i = 0, printed = 0;

	if (format == NULL)
		return (-1);

	va_start(a_ptr, format);
	for (i = 0; format[i]; i++)
	{
		if (format[i] != '%')
		{
			buffer[buf_i++] = format[i];
			if (buf_i == BUF_SIZE)
				print_buffer(buffer, &buf_i);
			char_count++;
		}
		else
		{
			print_buffer(buffer, &buf_i);
			i++;
			printed = 0;
			printed = get_printers(format, i, a_ptr, buffer);
			if (printed == -1)
				return (-1);
			char_count += printed;
		}
	}
	print_buffer(buffer, &buf_i);

	va_end(a_ptr);
	return (char_count);
}
