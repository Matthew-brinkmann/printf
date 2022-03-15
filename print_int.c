#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "main.h"

/**
  * print_int - function to print int %i
  * @b_info: copy of format integer pointed to %i
  * @var: va_list pointer
  * Return: if integer is NULL, return pointer
  */
t_buff *print_int(t_buff *b_info, va_list *var)
{
	unsigned long int number = 0, i = 0;
	char printNum[20];
	int initial_num, flag = 1;

	printf("in print int func");
	initial_num = va_arg(*var, int);
	if (initial_num < 0)
	{
		b_info->buffer[b_info->buff_loc] = '-';
		b_info->buff_loc++;
		b_info->buff_len++;
		flag = -1;
	}
	for (number = initial_num * flag; number > 9; i++)
	{
		*(printNum + i) = number % 10;
		number = number / 10;
	}
	*(printNum + i) = number;

	while (i >= 0)
	{
		b_info->buffer[b_info->buff_loc] = *(printNum + i);
		i--;
		b_info->buff_loc++;
		b_info->buff_len++;
	}

	return (b_info);
}
