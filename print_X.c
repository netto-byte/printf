#include "main.h"

/**
 * print_X - Converts and prints a base 10 value in base 16 (Uppercase)
 * @a_ptr: An argument pointer
 * @buffer: Buffer for formatting
 *
 * Return: Number of characters printed.
 */
int print_X(va_list a_ptr, char buffer[])
{
	char upperHex[] = "0123456789ABCDEF";
	unsigned int hex = va_arg(a_ptr, unsigned int);
	int i = BUF_SIZE - 2, count = 0, p;

	buffer[BUF_SIZE - 1] = '\0';

	if (hex == 0)
		buffer[i--] = '0';

	while (hex > 0)
	{
		buffer[i--] = upperHex[hex % 16];
		hex /= 16;
	}
	i++;

	for (p = i; buffer[p]; p++)
		count += write(1, &buffer[p], 1);
	return (count);
}
