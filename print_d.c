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
	int i = BUF_SIZE - 2, count = 0, flag = 0;
	long int num = va_arg(a_ptr, long int);
	unsigned long n;

	buffer[BUF_SIZE - 1] = '\0';

	n = (int)num;
	if (n == 0)
		buffer[i--] = '0';
	num = (unsigned long int)n;
	if (num < 0)
	{
		flag = 1;
		num = (unsigned long int)((-1) * n);
	}

	while (num > 0)
	{
		buffer[i--] = '0' + (num % 10);
		num /= 10;
		count++;
	}
	if (flag == 1)
		buffer[i--] = '-', count++;
	i++;

	return (write(1, &buffer[i], count));
}
