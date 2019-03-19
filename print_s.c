#include "holberton.h"

/**
 * print_s - prints a string.
 * @list: list of arguments.
 *
 * Return: Always 0 (success).
 */
int print_s(va_list list)
{
	char *x;
	int y = 0;

	x = va_arg(list, char *);
	if (!x)
		x = "(null)";
	while (x[y] != 0)
	{
		_putchar(x[y]);
		y++;
	}
	return (0);
}
