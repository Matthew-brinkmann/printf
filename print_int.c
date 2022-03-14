#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "main.h"

/**
  * print_int - function to print int %i
  * @format: copy of format integer pointed to %i
  * @var: va_list pointer
  * Return: if integer is NULL, return pointer
  */
char *print_int(char *format, va_list *var)
{
	char *formatEnd;
	char intToChar[32];
	int argInt, orgInt, i = 0, a = 0

	argInt = va_arg(*var, int);
	orgInt = argInt;
	formatEnd = malloc(sizeof(*formatEnd) * (_strlen(format) + 1));
	if (formatEnd == NULL)
		return (format);
	_strcpy(formatEnd, format);

	if (orgInt < 0)
		argInt = -argInt;

	while (argInt > 9)
	{
		intToChar[i] = argInt % 10 + 48;
		argInt = argInt / 10;
		i++;
	}
	intToChar[i] = argInt + 48;
	if (orgInt < 0)
	{
		i++;
		intToChar[i] = '-';
	}
	while (i >= 0)
	{
		*(format + a) = intToChar[i];
		a++;
		i--;
	}
	format = format + a;
	if (_strlen(formatEnd) > 2)
		_strcpy(format, formatEnd + 2);
	else
		*format = '\0';
	free(formatEnd);
	return (format);
}
