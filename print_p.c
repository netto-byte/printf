#include "main.h"

/**
 * print_p - Prints the address of a memory.
 * @a_ptr: An argument pointer
 * @buffer: Buffer for formatting
 *
 * Return: Number of characters printed.
 */
int print_p(va_list a_ptr, char buffer[])
{
	void *ptr = va_arg(a_ptr, void *);
	char hex[] = "0123456789abcdef";
	int i = BUF_SIZE - 2, count = 0, p;
	unsigned long address;

	buffer[BUF_SIZE - 1] = '\0';

	if (ptr == NULL)
		return (write(1, "(nil)", 5));
	address = (unsigned long)ptr;
	while (address > 0)
	{
		buffer[i--] = hex[address % 16];
		address /= 16;
	}
	buffer[i--] = 'x';
	buffer[i] = '0';

	for (p = i; buffer[p]; p++)
		count += write(1, &buffer[p], 1);
	return (count);
}
