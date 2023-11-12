#include "main.h"
/**
 * _putchar_buffer - print char with stdout
 * @ch: char to print
 * Return: Output.
 */
int _putchar_buffer(char ch)
{
	static int contador;
	static char buffer[1024];

	if (ch == -1)
	{
		contador = 0;
		return (0);
	}
	if (ch == -2 || contador == 1024)
	{
		write(1, buffer, contador);
		contador = 0;
	}
	if (ch != -1 && ch != -2)
	{
		buffer[contador] = ch;
		contador++;
		return (1);
	}
	return (0);
}
/**
 * _putstr - prints a string
 * new line, to stdout.
 * @string: input string
 * Return: count of string.
 */
int _putstr(char *string)
{
	int contador = 0;

	while (*string)
	{
		_putchar_buffer(*string);
		string++;
		contador++;
	}
	return (contador);
}

/**
 * printcha - prints a char.
 * @pa: format of char.
 * @format: format
 * Return: number char for printf.
 */
int printcha(char *format, va_list pa)
{
	(void)format;
	_putchar_buffer(va_arg(pa, int));
	return (1);
}

/**
 * printhexadecimal - prints a hexadecimal
 * @format: format to print hexadecimal
 * @pa: list that contains the hexadecimal
 * Return: number.
 */
int printhexadecimal(char *format, va_list pa)
{
	unsigned int num = va_arg(pa, unsigned int);
	unsigned int num2;
	int i, i2, copy, contame = 0;
	char *numhex;

	(void)format;

	if (num == 0)
		return (_putchar_buffer('0'));
	for (num2 = num; num2 != 0; contame++)
	{
		num2 = num2 / 16;
	}
	numhex = malloc(contame);
	for (i = 0; num != 0; i++)
	{
		copy = num % 16;
		if (copy < 10)
			numhex[i] = copy + '0';
		else
			numhex[i] = copy - 10 + 'a';
		num = num / 16;
	}
	for (i2 = i - 1; i2 >= 0; i2--)
		_putchar_buffer(numhex[i2]);
	free(numhex);
	return (contame);
}
/**
 * printHEXADECIMAL - prints a hexadecimal
 * @format: format to print hexadecimal
 * @pa: va_list that contains the hexadecimal to print
 * Return: number of digits printed
 */
int printHEXADECIMAL(char *format, va_list pa)
{
	unsigned int NUM = va_arg(pa, unsigned int);
	unsigned int NUM2;
	int I, I2, COPY, CONTAME = 0;
	char *NUMHEX;

	(void)format;

	if (NUM == 0)
		return (_putchar_buffer('0'));
	for (NUM2 = NUM; NUM2 != 0; CONTAME++)
	{
		NUM2 = NUM2 / 16;
	}
	NUMHEX = malloc(CONTAME);
	for (I = 0; NUM != 0; I++)
	{
		COPY = NUM % 16;
		if (COPY < 10)
			NUMHEX[I] = COPY + '0';
		else
			NUMHEX[I] = COPY - 10 + 'A';
		NUM = NUM / 16;
	}
	for (I2 = I - 1; I2 >= 0; I2--)
		_putchar_buffer(NUMHEX[I2]);
	free(NUMHEX);
	return (CONTAME);
}
