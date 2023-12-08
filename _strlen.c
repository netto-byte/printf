#include "main.h"

/**
 * _strlen - Gets the length of a string
 * @str: A string to compute
 *
 * Return: Number of characters in str.
 */
int _strlen(char *str)
{
	int len = 0;

	while (str[len])
		len++;
	return (len);
}
