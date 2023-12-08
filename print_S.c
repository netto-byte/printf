#include "main.h"

/**
 * print_S - Prints both printable and non-printable characters.
 * a_ptr: An argument pointer
 * @buffer: Buffer for formatting
 *
 * Return: Number of characters printed.
 */
int print_S(va_list a_ptr, char buffer[])
{
	char *str = va_arg(a_ptr, char *);
	char hex[] = "0123456789ABCDEF";
	int i = 0, j = 0, count = 0, non_printable = 0;

	if (str == NULL)
		str = "(null)";
	while (str[i])
	{
		if (str[i] >= 32 && str[i] < 127)
			buffer[j++] = str[i];
		else
		{
			non_printable = str[i];
			if (non_printable < 0)
				non_printable *= -1;
			buffer[j++] = '\\';
			buffer[j++] = 'x';
			buffer[j++] = hex[non_printable / 16];
			buffer[j++] = hex[non_printable % 16];
		}
		i++;
	}
	buffer[j] = '\0';

	for (j = 0; buffer[j]; j++)
		count += write(1, &buffer[j], 1);
	return (count);
}
