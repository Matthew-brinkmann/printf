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

t_buff *print_mod(va_list *var, t_buff *b_info)
{
	unsigned int count = 0;
	t_mod selector[] = {
		{"c", print_char},
		{"s", print_string},
		{"d", print_int},
		{"i", print_int},
		/*{"b", print_binary},
		{"o", print_eight},
		{"x", print_sixteen},
		{"X", print_u_sixteen},
		{"u", print_uns},
		{"p", print_ptr},*/
		{NULL, NULL}
	};
	printf("in mod function\n");
	printf("buff: %s\n", b_info->buffer);
	b_info->form_loc++;
	if (b_info->format[b_info->form_loc] == '%')
	{
		b_info->buffer[b_info->buff_loc]
				= b_info->format[b_info->form_loc];
		b_info->buff_len++;
		b_info->buff_loc++;
		return (b_info);
	}

	while (selector[count].symbol != NULL)
	{
		if (*(selector[count].symbol) ==
		    b_info->format[b_info->form_loc])
		{
			selector[count].type(b_info, var);
			break;
		}
		count++;
	}
	return (b_info);
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
	va_list print;
	t_buff *buff_info;
	int totalBytes;

	printf("start code\n");
	if (format == NULL)
		return (-1);

	va_start(print, format);
	buff_info = buff_size_calc(format);
	/**
	 * These loops will find the modifier character and will
	 * send to the print_mod function to do the heavy lifting.
	 */
	while (buff_info->format[buff_info->form_loc] != '\0')
	{
		if (*(format + buff_info->form_loc) == '%')
		{
			buff_info = print_mod(&print, buff_info);
		} else
		{
			buff_info->buffer[buff_info->buff_loc]
				= format[buff_info->form_loc];
			buff_info->buff_len++;
			buff_info->buff_loc++;
		}
		buff_info->form_loc++;
	}
	va_end(print);
	write(1, buff_info->buffer, buff_info->buff_len);
	totalBytes = buff_info->buff_len;
	_buff_free(buff_info);
	return (totalBytes);
}
