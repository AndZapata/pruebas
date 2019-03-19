#include "holberton.h"

/**
 * print_id - prints an integer or a decimal.
 * @list: list of arguments.
 *
 * Return: counter.
 */
int print_id(va_list list)
{
	int count, num;

	count = 0;
	num = va_arg(list, int);
	count += recursive_print(num);
	return (count);
}

/**
 * recursive_print - processes the int argument acordding to d or i
 * @num: number to print recursively.
 *
 * Return: counter.
 */
int recursive_print(int num)
{
	int count = 0;
	unsigned int x = num;

	if (num < 0)
	{
		count += _putchar('-');
		x = -x;
	}
	if (x / 10)
		count += recursive_print(x / 10);
	count += _putchar(x % 10 + '0');
	return (count);
}
