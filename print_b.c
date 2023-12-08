#include "main.h"

/**
 * print_b - Prints an unsigned int in binary
 * @a_ptr: An argument pointer
 * @buffer: Buffer for formatting
 *
 * Return: Number of characters printed.
 */
int print_b(va_list a_ptr, char buffer[])
{
	unsigned int bin = va_arg(a_ptr, unsigned int);
	int i = BUF_SIZE - 2, count = 0, p;

	buffer[BUF_SIZE - 1] = '\0';
	if (bin == 0)
		buffer[i--] = '0';
	while (bin > 0)
	{
		buffer[i--] = '0' + (bin % 2);
		bin /= 2;
	}
	i++;

	for (p = i; buffer[p]; p++)
		count += write(1, &buffer[p], 1);
	return (count);
}
