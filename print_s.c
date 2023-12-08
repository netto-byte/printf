#include "main.h"

/**
 * print_s - Prints a string to the stdout.
 * @a_ptr: An argument pointer.
 * @buffer: Buffer for formatting
 *
 * Return: Number of characters printed.
 */
int print_s(va_list a_ptr, char buffer[])
{
	char *str = va_arg(a_ptr, char *);

	(void)buffer;

	if (str == NULL)
		str = "(null)";

	return (write(1, str, _strlen(str)));
}
