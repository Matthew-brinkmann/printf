#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/**
 * print_binary - converts an unsigned int to base2 and inserts into string
 * @format: the string to be modified
 * @var: the va_list to be accessed
 * Return: pointer to the modified string
 */

char *print_binary(char *format, va_list *var)
{
	char *formatEnd, newStr[32];
	unsigned int arg, i, idx;
	int argTest = 0;

	arg = va_arg(*var, unsigned int);
	argTest = arg;
	if (argTest < 0)
		exit(101);

	formatEnd = malloc(sizeof(*formatEnd) * (_strlen(format) + 1));
	if (formatEnd == NULL)
		return (NULL);
	_strcpy(formatEnd, format);

	idx = 0;
	while (arg / 2 != 0)
	{
		newStr[idx] = (arg % 2) + 48;
		arg = arg / 2;
		idx++;
	}
	newStr[idx] = (arg % 2) + 48;

	i = 0;
	while (idx > 0)
	{
		format[i] = newStr[idx];
		i++;
		idx--;
	}
	format[i] = newStr[idx];

	format = format + i + 1;

	if (_strlen(formatEnd) > 2)
		_strcpy(format, formatEnd + 2);
	else
		*format = '\0';

	return (format);
}
