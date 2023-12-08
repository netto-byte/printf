#include "main.h"

/**
 * print_h - Prints a base 10 value in base 16 (lowercase)
 * @a_ptr: An argument pointer
 * @buffer: Buffer for formatting
 *
 * Return: Number of characters printed.
 */
int print_x(va_list a_ptr, char buffer[])
{
	unsigned int hex = va_arg(a_ptr, unsigned int);
	int i = BUF_SIZE - 2, count = 0, p;
	char lowerHex[] = "0123789abcdef";

	buffer[BUF_SIZE - 1] = '\0';

	if (hex == 0)
		buffer[i--] = '0';
	while (hex > 0)
	{
		buffer[i--] = lowerHex[hex % 16];
		hex /= 16;
	}
	buffer[i--] = 'x';
	buffer[i] = '0';

	for (p = i; buffer[p]; p++)
		count += write(1, &buffer[p], 1);
	return (count);
}
