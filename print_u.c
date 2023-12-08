#include "main.h"

/**
 * print_u - Prints an unsigned int
 * @a_ptr: An argument pointer
 * @buffer: Buffer for formatting
 *
 * Return: Number of characters printed.
 */
int print_u(va_list a_ptr, char buffer[])
{
	unsigned int num = va_arg(a_ptr, unsigned int);
	int i = BUF_SIZE - 2, count = 0, p;

	buffer[BUF_SIZE - 1] = '\0';

	if (num == 0)
		buffer[i--] = '0';
	while (num > 0)
	{
		buffer[i--] = '0' + (num % 10);
		num /= 10;
	}
	i++;

	for (p = i; buffer[p]; p++)
		count += write(1, &buffer[p], 1);
	return (count);
}
