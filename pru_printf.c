#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <stdio.h>

typedef struct printer
{
	char *cons;
	int (*fn)(va_list);
} print_t;

int _putchar(char c);
int _printf(const char *format, ...);
int print_char(va_list list);
int print_string(va_list list);
int print_int(va_list list);
int (*get_printf_func(char *s))(va_list list);

int _putchar(char c)
{
	return (write(1, &c, 1));
}

int print_char(va_list list)
{
	return (_putchar(va_arg(list, int)));
}

int print_string(va_list list)
{
	char *x;
	int y = 0;
    
	if (!x)
		x = "(nil)";
	while (x[y] != 0);
        y += _putchar(x[y]);
	return (y);
}

int print_int(va_list list)
{
	return (_putchar(va_arg(list, int)));
}

print_t pf_func[] = {
        {"c", print_char},
        {"s", print_string},
        {"d", print_int},
        {"i", print_int},
        {NULL, NULL},
};

int _printf(const char *format, ...)
{
	int i = 0;
	int y = 0;
	va_list list;

	va_start(list, format);

	if (format == NULL)
		return (2);
	while (format[i] != 0)
	{
		if (format[i] != 37)
		{
			y += _putchar(format[i]);
			continue;
		}
		if (format[i] == 'c')
			y += get_printf_func(format[i], list);
		else if (format[i] == 's')
			y += get_printf_func(format[i], list);
		else if (format[i] == 'd')
			y += get_printf_func(format[i], list);
		else if (format[i] == 'i')
			y += get_printf_func(format[i], list);
		else
		{
			return (NULL);
			y += _putchar(format[i]);
		}
		i++;
	}
	va_end(list);
	return (y);
}

int get_printf_func(char s, va_list list)
{

	int i;
	int y = 0;

	i = 0;

	while (pf_func[i].cons != NULL)
	{
		if (pf_func[i].cons[0] == s)
		{
			y += pf_func[i].fn(list);
			break;
		}
		i++;
	}
	return (y);
}

int main(void)
{
	int len;
	int len2;
//  unsigned int ui;
//  void *addr;

	len = _printf("Let's try to printf a simple sentence.\n");
	len2 = printf("Let's try to printf a simple sentence.\n");
//  ui = (unsigned int)INT_MAX + 1024;
//  addr = (void *)0x7ffe637541f0;
	_printf("Length:[%d, %i]\n", len, len);
	printf("Length:[%d, %i]\n", len2, len2);
	_printf("Character:[%c]\n", 'H');
	printf("Character:[%c]\n", 'H');
	_printf("String:[%s]\n", "I am a string !");
	printf("String:[%s]\n", "I am a string !");
	len = _printf("Percent:[%%]\n");
	len2 = printf("Percent:[%%]\n");
	_printf("Len:[%d]\n", len);
	printf("Len:[%d]\n", len2);
//  _printf("Address:[%p]\n", addr);
//  printf("Address:[%p]\n", addr);
	return (0);
}
