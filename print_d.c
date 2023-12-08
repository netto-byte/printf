#include "main.h"

/**
 * print_d - Prints an integer passed as parameter to _printf
 * @a_ptr: Argument pointer
 * @buffer: Buffer for formatting
 *
 * Return: Number of characters printed.
 */
int print_d(va_list a_ptr, char buffer[])
{
	int num, i, flag = 0, count = 0;

	num = va_arg(a_ptr, int);

	if (num < 0)
	{
		flag = 1;
		num *= -1;
	}

	buffer[BUF_SIZE - 1] = '\0';
	i = BUF_SIZE - 2;
	while (num > 0)
	{
		buffer[i--] = '0' + (num % 10);
		num /= 10;
		count++;
	}
	if (flag)
		buffer[i--] = '-', count++;
	i++;

	return (write(1, &buffer[i], count));
}
