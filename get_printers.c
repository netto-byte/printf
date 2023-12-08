#include "main.h"

/**
 * get_printers - Selects the proper function for a specifier.
 * @format: Format string
 * @fmt_i: Index for specifier in the format string.
 * @a_ptr: An argument pointer
 * @buffer: Buffer for formatting
 *
 * Return: Number of characters printed from a particular function.
 */
int get_printers(const char *format, int fmt_i, va_list a_ptr, char buffer[])
{
	print_t select[] = {
		{'c', print_c}, {'s', print_s},
		{'%', print_percent}, {'d', print_d},
		{'i', print_d}, {'b', print_b},
		{'\0', NULL}
	};
	int i, count;

	for (i = 0; select[i].c; i++)
		if (select[i].c == format[fmt_i])
			return (select[i].func(a_ptr, buffer));

	count = 0;
	if (select[i].c == '\0')
	{
		if (format[i] == '\0')
			return (-1);

		count += write(1, "%%", 1);
		if (format[i - 1] == ' ')
			count += write(1, " ", 1);
		count += write(1, &format[i], 1);
		return (count);
	}

	return (-1);
}
