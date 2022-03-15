#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
  * print_char - function to print char %c
  * @b_info: copy of format char pointed to %c
  * @var: the list to manipulate.
  * Return: if char is NULL, return pointer
  */
t_buff *print_char(t_buff *b_info, va_list *var)
{
	char arg;

	arg = va_arg(*var, int);

	b_info->buffer[b_info->buff_loc]
		= arg;
	b_info->buff_len++;
	b_info->buff_loc++;

	return (b_info);
}
