#include "main.h"

/**
 * print_r - Prints a string in reverse
 * @a_ptr: An argument pointer
 * @buffer: Buffer for formatting
 *
 * Return: Number of characters printed.
 */
int print_r(va_list a_ptr, char buffer[])
{
	char *str = va_arg(a_ptr, char *);
	int i = BUF_SIZE - 2, count = 0, j = 0;

	if (str == NULL)
		return (write(1, ")llun(", 6));

	buffer[BUF_SIZE - 1] = '\0';
	while (str[j])
		buffer[i--] = str[j++];
	i++;

	for (; buffer[i]; i++)
		count += write(1, &buffer[i], 1);
	return (count);
}
