#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * print_mod - will search for the required modifier function
 * @format: the string we want manipulate
 * @var: the list to search from
 * Description: long description
 *
 * Return: the pointer to the string after the modification has occured
 */

char *print_mod(char *format, va_list *var)
{
	unsigned int count = 0;
	char modFound = *(format + 1);
	t_mod selector[] = {
		{"c", print_char},
		{"s", print_string},
		{"d", print_int},
		{"i", print_int},
		{"b", print_binary},
		{"o", print_eight},
		{"x", print_sixteen},
		{"X", print_sixteen},
		{"u", print_uns},
		{NULL, NULL}
	};

	if (*(format + 1) == '%')
	{
		remove_char(format);
		return (format);
	}

	while (selector[count].symbol != NULL)
	{
		if (*(selector[count].symbol) == *(format + 1))
		{
			return (selector[count].type(format, var));
		}
		count++;
	}
	_puts("Error: incorrect Modifier %");
	_putchar(modFound);
	_putchar('\n');
	exit(99);
}

/**
 * _printf - will duplicate the printf function
 * @format: the string we want manipulate
 * Description: long description
 *
 * Return: count of the length printed to screen
 */

int _printf(const char *format, ...)
{
	va_list print, search;
	unsigned int i = 0;
	char *formatCpy;
	int buffSize;

	/**
	 * the next few lines will allocate space
	 * and copy the original string to a new
	 * location on the heap for us to manipulate
	 */
	va_start(print, format);
	va_copy(search, print);
	buffSize = buff_size_calc(format, &search);
	va_end(search);
	formatCpy = malloc(buffSize);
	_strcpy(formatCpy, format);

	/**
	 * These loops will find the modifier character and will
	 * send to the print_mod function to do the heavy lifting.
	 */
	while (formatCpy != NULL && (*(formatCpy + i)) != '\0')
	{
		if (*(formatCpy + i) == '%')
		{
			print_mod(formatCpy + i, &print);
		}
		i++;
	}
	va_end(print);
	buffSize = _strlen(formatCpy);
	write(1, formatCpy, buffSize);
	free(formatCpy);
	return (buffSize);
}
