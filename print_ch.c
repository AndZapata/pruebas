#include "holberton.h"
/**
 * print_ch - prints a character in the ascii list
 * @list: list of arguments.
 *
 * Return: a char argument in the list.
 */
int print_ch(va_list list)
{
	return (_putchar(va_arg(list, int)));
}
