#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/**
  * print_string - function to print string %s
  * @format: copy of format string pointed to %s
  * @var: va_list pointer
  * Return: if string is NULL, return pointer
  */
t_buff *print_string(t_buff *b_info, va_list *var)
{
	char *argStr;
	int count = 0, len;

	argStr = va_arg(*var, char *);
	len = _strlen(argStr);

	if (argStr == NULL || *argStr == '\0')
		return (b_info);

	while (count <= len)
	{
		b_info->buffer[b_info->buff_loc]
			= argStr[count];
		count++;
		b_info->buff_loc++;
	}
	b_info->buff_len = b_info->buff_len + len + 1;

	return (b_info);
}
