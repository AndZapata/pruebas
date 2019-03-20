#include "holberton.h"
/**
 * _printf - Prints determined arguments into formatted standard output
 * @format: content that has to be in list of arguments
 *
 * Return: counter.
 */
int _printf(const char *format, ...)
{
	prints pf_func[] = {
		{"%", print_ch},
		{"c", print_ch},
		{"s", print_s},
		{"d", print_id},
		{"i", print_id},
		{NULL, NULL},
	};
	int i = 0, j = 0, y = 0;
	va_list list;

	va_start(list, format);
	if (format == NULL)
		return (-1);
	while (format[i] != 0)
	{
		if (format[i] != 37)
		{ y += _putchar(format[i]);
			i++;
			continue; }
		i++;
		while (pf_func[j].cons != NULL)
		{
			if (pf_func[j].cons[0] == format[i])
			{
				if (pf_func[j].cons[0] == 37)
				{ y += percent(); }
				else
					y += pf_func[j].func(list);
				break; }
			j++;
			if (pf_func[j].cons == NULL)
			{ y += _putchar(format[i - 1]);
				y += _putchar(format[i]);
			}
		}
		i++;
	}
	va_end(list);
	return (y);
}
