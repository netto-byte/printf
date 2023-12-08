#include "main.h"

/**
 * print_R - Prints a string in ROT13 format
 * @a_ptr: An argument pointer
 * @buffer: Buffer for formatting
 *
 * Return: Number of characters printed.
 */
int print_R(va_list a_ptr, char buffer[])
{
	char *from = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char *to = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	char *str = va_arg(a_ptr, char *);
	int i, j, k = 0, count = 0;

	if (str == NULL)
		return (write(1, "(AHYY)", 6));
	for (i = 0; str[i]; i++, j++;)
	{
		for (j = 0; from[j]; j++)
		{
			if (str[i] == from[j])
			{
				buffer[k++] = to[j];
				break;
			}
		}
		if (from[j] == '\0')
			buffer[k++] = str[i];
	}
	buffer[k] = '\0';

	for (i = 0; buffer[i]; i++)
		count += write(1, &buffer[i], 1);
	return (count);
}
