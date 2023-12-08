#include "main.h"

/**
 * print_buffer - Prints the content of a buffer
 * and reset it's size
 * @buffer: Buffer to print
 * @size: Size of buffer
 */
void print_buffer(char buffer[], int *size)
{
	if (*size > 0)
		write(1, &buffer[0], *size);
	*size = 0;
}
