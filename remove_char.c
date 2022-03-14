#include <stdarg.h>
#include <stdlib.h>
#include "main.h"

/**
 * remove_char - inserts \b into a string to remove an unwanted char
 * @format: the string to be altered
 * Return: pointer to the altered string or NULL
 */
char *remove_char(char *format)
{
	char *formatEnd;

	formatEnd = malloc(_strlen(format) + 1);

	if (formatEnd == NULL)
		return (NULL);

	_strcpy(formatEnd, format);

	if (_strlen(formatEnd) > 2)
		_strcpy(format + 1, formatEnd + 2);
	else
		*(format + 1) = '\0';

	free(formatEnd);

	return (format);
}
