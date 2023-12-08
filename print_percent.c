#include "main.h"

/**
 * print_percent - Prints the percent character
 * @a_ptr: An argument pointer
 * @buffer: Buffer for formatting.
 *
 * Return: 1 on success,
 * -1 if error, and set errno appropriately.
 */
int print_percent(va_list a_ptr, char buffer[])
{
	(void)a_ptr;
	(void)buffer;

	return (write(1, "%%", 1));
}
