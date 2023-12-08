#include "main.h"

/**
 * print_c - Writes a character to the stdout
 * @a_ptr: An argument pointer
 * @buffer: Buffer for formatting
 *
 * Return: On success 1,
 * -1 if error, and set errno appropriately.
 */
int print_c(va_list a_ptr, char buffer[])
{
	char c = va_arg(a_ptr, int);

	(void)buffer;

	return (write(1, &c, 1));
}
