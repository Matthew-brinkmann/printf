#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "main.h"

/**
  * print_char - function to print char %c
  * @format: copy of format char pointed to %c
  * @format: the string character to manipulate
  * @var: the list to manipulate.
  * Return: if char is NULL, return pointer
  */
char *print_char(char *format, va_list *var)
{
	char *formatEnd;
	char *c;
	int i = 0; /*placeholder of c */

	c = va_arg(*var, char *);
	if((c == NULL) || (*c == '\0') || (*(c + 1) != '\0'))
		return (format);

	formatEnd = malloc(sizeof(*formatEnd) * (_strlen(format) + 1));
	if (formatEnd == NULL)
		return (format);
	_strcpy(formatEnd, format);
	_strcpy(format, c);

	format = format + _strlen(c);
	if (_strlen(formatEnd) > 2)
		_strcpy(format, formatEnd + 2);

	free(formatEnd);
	return (format);
}
