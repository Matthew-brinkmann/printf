#include <stdio.h>
#include <stdarg.h>
#include "main.h"
#include <stdlib.h>


/**
 * buff_size_calc - calcs the maximum size needed for the buffer
 * @format: the type of data we need
 * @args: pointer to the list for the printf
 * Description: long description
 *
 * Return: add in what is supposed to be returned if anything
 */
int buff_size_calc(const char *format, va_list *args)
{
	int i = 0, count = 0, k = 0;
	int buffSize = 0;
	t_buff selector[] = {
		{"c", buff_char},
		{"s", buff_string},
		{"d", buff_int},
		{"i", buff_int},
		{"f", buff_float},
		{"o", buff_eight},
		{"x", buff_sixteen},
		{"X", buff_sixteen},
		{"u", buff_int},
		{NULL, NULL}
	};

	buffSize = _strlen(format);
	while (format != NULL && (*(format + i)) != '\0')
	{
		count = 0;
		while (selector[count].symbol != NULL)
		{
			k = i + 1;
			if ((*(format + i) == '%') && (*(format + k) == '%'))
			{
				buffSize++;
				i++;
				break;
			}
			if (*(selector[count].symbol) == *(format + i))
			{
				k = i - 1;
				if (*(format + k) == '%')
				buffSize = buffSize +
					selector[count].type(args);
			}
			count++;
		}
		i++;
	}
	return (buffSize);
}
