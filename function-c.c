#include "main.h"

/**
 * printpercentage - prints %
 * @format: format
 * @pa: va_list
 * Return: number of characters printed
 */
int printpercentage(char *format, va_list pa)
{
	(void)format;
	(void)pa;
	_putchar_buffer('%');
	return (1);
}

/**
 * printstring- print str.
 * @pa: gtgtg
 * @format: format str.
 * Return: number str for print.
 */
int printstring(char *format, va_list pa)
{
	char *string = va_arg(pa, char *);
	int contador;
	(void)format;

	if (string == NULL)
		string = "(null)";
	contador = _putstr(string);
	return (contador);
}
