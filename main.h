#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

/**
 * struct structprint - structure containing
 * @q: the location and method to translate data to characters.
 * @u: print function for specific type.
 *
 * Return: int
 */
typedef struct structprint
{
	char *q;
	int (*u)(char *format, va_list);
} habiba;

int _putchar_buffer(char ch);
int _putstr(char *string);
int printcha(char *format, va_list);
int printstring(char *format, va_list);
int (*struct_checker(char *format))(char *format, va_list);
int _printf(char *format, ...);
int printint_g(char *format, va_list pa);
int integers(int number);
int contadordigits(int number);
int _absloute(int number);
int printpercentage(char *format, va_list pa);
int printhexadecimal(char *format, va_list);
int printHEXADECIMAL(char *format, va_list);
int printoctal(char *format, va_list);


#endif
