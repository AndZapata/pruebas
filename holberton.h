#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

/**
 * struct printer - Struct op
 *
 * @cons: The string of special chars
 * @func: The function associated
 */
typedef struct printer
{
	char *cons;
	int (*func)(va_list);
} prints;

int _putchar(char c);
int percent(void);
int print_ch(va_list list);
int print_s(va_list list);
int print_id(va_list list);
int recursive_print(int num);
int _printf(const char *format, ...);

#endif /* _HOLBERTON_H_ */
