#include <stdio.h>
#include <stdarg.h>
#include "main.h"
#include <stdlib.h>

/**
  * print_sixteen - function to print of base 16
  * @format: base16
  * @var: the list object to manipulate.
  * Return: if argument is NULL, return pointer
  */
char *print_sixteen(char *format, va_list *var)
{
	char *formatEnd;
	unsigned int number = 0;
	int numberTest = 0;
	char printNum[20], i = 0;
	char *convert = "0123456789abcdef";

	number = va_arg(*var, unsigned int);
	numberTest = number;
	/* perhaps we should exit here instead as printf wouldn't compile */
	formatEnd = malloc(sizeof(*formatEnd) * (_strlen(format) + 1));
	if (formatEnd == NULL)
		return (format);
	if (numberTest < 0)
		number = number * -1;
	while (number > 15)
	{
		*(printNum + i) = *(convert + (number % 16));
		i++;
		number = number / 16;
	}
	*(printNum + i) = *(convert + (number % 16));
	if (numberTest < 0)
	{
		i++;
		*(printNum + i) = '-';
	}
	i++;
	*(printNum + i) = '\0';
	rev_string(printNum);
	_strcpy(formatEnd, format);
	_strcpy(format, printNum);

	format = format + _strlen(printNum);
	if (_strlen(formatEnd) > 2)
		_strcpy(format, formatEnd + 2);

	free(formatEnd);
	return (format);
}
