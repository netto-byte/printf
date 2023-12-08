#include "main.h"

/**
 * print_o - Prints a base 10 number in base 8
 * @a_ptr: An argument pointer
 * @buffer: Buffer for formatting
 *
 * Return: Number of characters printed.
 */
int print_o(va_list a_ptr, char buffer[])
{
	unsigned int octal = va_arg(a_ptr, unsigned int);
	int i = BUF_SIZE - 2, p, count = 0;

	buffer[BUF_SIZE - 1] = '\0';

	if (octal == 0)
		buffer[i--] = '0';
	while (octal > 0)
	{
		buffer[i--] = '0' + (octal % 8);
		octal /= 8;
	}
	i++;

	for (p = i; buffer[p]; p++)
		count += write(1, &buffer[p], 1);
	return (count);
}
