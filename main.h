#ifndef _MAIN_H_
#define _MAIN_H_

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

#define BUF_SIZE 1024

/**
 * struct printers - A printer struct
 * @c: A char variable
 * @func: Function pointer
 *
 * Description: For selecting print functions
 */
typedef struct printer
{
	char c;
	int (*func)(va_list a_ptr, char format[]);
} print_t;

/* FUNCTIONS */
int _printf(const char *format, ...);

int print_c(va_list a_ptr, char format[]);
int print_s(va_list a_ptr, char format[]);
int print_percent(va_list a_ptr, char format[]);

int _strlen(char *string);
void print_buffer(char buffer[], int *size);
int get_printers(const char *format, int fmt_t, va_list a_ptr, char buffer[]);

#endif /* _MAIN_H_ */
