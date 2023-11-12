#include "main.h"
/**
 * _absloute - calculates the absolute value.
 * @number: input.
 * Return: value.
 */
int _absloute(int number)
{
	if (number < 0)
		return (-1 * number);
	else
		return (number);
}

/**
 * contadordigits - counts the digits.
 * @number: input integer
 * Return: digit count
 */
int contadordigits(int number)
{
	int count = 0;
	int number2 = number;

	if (number <= 0)
		count += 1;

	while (_absloute(number2) != 0)
	{
		number2 = number2 / 10;
		count++;
	}
	return (count);
}
/**
 * integers - a function that prints an integer.
 * @number: input integer
 * Return: digit count
 */
int integers(int number)
{
	unsigned int unint;
	int count;

	count = contadordigits(number);
	if (number < 0)
	{
		_putchar_buffer('-');
		unint = -number;
	}
	else
		unint = number;

	if (unint >= 10)
		integers(unint / 10);
	_putchar_buffer(unint % 10 + '0');

	return (count);
}

/**
 * printint_g - prints a number
 * @format: format to print number
 * @pa: va_list with number to print
 * Return: number of characters printed
 */
int printint_g(char *format, va_list pa)
{
	int number = va_arg(pa, int);
	int numero;
	(void)format;

	numero = integers(number);

	return (numero);
}

/**
 * printoctal - prints a hexadecimal
 * @format: format to print hexadecimal
 * @pa: list that contains the hexadecimal
 * Return: number.
 */
int printoctal(char *format, va_list pa)
{
	unsigned int num = va_arg(pa, unsigned int);
	unsigned int copia;
	char *octa;
	int i, i2 = 0, contame = 0;
	(void)format;

	if (num == 0)
		return (_putchar_buffer('0'));
	for (copia = num; copia != 0; i2++)
	{
		copia = copia / 8;
	}
	octa = malloc(i2);
	if (!octa)
		return (-1);
	for (i = i2 - 1; i >= 0; i--)
	{
		octa[i] = num % 8 + '0';
		num = num / 8;
	}
	for (i = 0; i < i2 && octa[i] == '0'; i++)
		;
	for (; i < i2; i++)
	{
		_putchar_buffer(octa[i]);
		contame++;
	}
	free(octa);
	return (contame);
}
