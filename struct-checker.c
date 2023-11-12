#include "main.h"

/**
 * struct_checker - selector for type of fun.
 * @format: string.
 * Description: the function loops through the structs
 * selector[] ment of the struct.
 * Return: a pointer
 * structype - Struct
 * selector - h
 */

int (*struct_checker(char *format))(char *format, va_list)
{
	int i;

	habiba selector[] = {
		{"%c", printcha},
		{"%s", printstring},
		{"%d", printint_g},
		{"%i", printint_g},
		{"%%", printpercentage},
		{"%x", printhexadecimal},
		{"%X", printHEXADECIMAL},
		{"%o", printoctal},
		{NULL, NULL}};

	if (format[1] == ' ' || format[1] == '\0')
		return (NULL);
	for (i = 0; selector[i].q; i++)
	{
		if (format[1] == selector[i].q[1])
			return (selector[i].u);
	}
	return (NULL);
}
