#include "main.h"

/**
 * _printf - prints formatted data to stdout
 * @format: string that contains the format to print
 * Return: number of characters written
 */
int _printf(char *format, ...)
{int written = 0, (*structype)(char *, va_list);
	char q[3];
	va_list pa;
	/* Check if the format string is NULL or an empty format string */
	if (format == NULL || (format[0] == '%' && !format[1]))
		return (-1);
	q[2] = '\0';		  /*Ensure the 'q' string is null-terminated*/
	va_start(pa, format); /*Start variable argument list*/
	_putchar_buffer(-1);  /* Initialize the character buffer*/
	while (format[0])
	{/* Check for format specifiers */
		if (format[0] == '%')
		{
			structype = struct_checker(format);
			if (structype)
			{/* Format specifier found, prepare 'q' with '%X' for example */
				q[0] = '%';
				q[1] = format[1];
				/* Call the appropriate function for the format specifier */
				written += structype(q, pa);
			}
			else if (format[1] != '\0')
			{/* No matching format specifier, print '%' and the character */
				written += _putchar_buffer('%');
				written += _putchar_buffer(format[1]);
			}
			else
			{/* Handle '%' at the end of the format string */
				written += _putchar_buffer('%');
				break;
			}
			format += 2; /* Move the format pointer past the specifier*/
		}
		else
		{/* Regular character, print it */
			written += _putchar_buffer(format[0]);
			format++;
		}
	}
	_putchar_buffer(-2); /* Flush the character buffer*/
	return (written); /* Return the total number of characters written*/
}
