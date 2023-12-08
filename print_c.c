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
	int i = BUF_SIZE - 2;
	char c = va_arg(a_ptr, int);

	buffer[BUF_SIZE -1] = '\0';
	buffer[i] = c;

	return (write(1, &buffer[i], 1));
}
