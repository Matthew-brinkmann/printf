#include <stdio.h>
#include <stdarg.h>
#include "main.h"
#include <stdlib.h>

/**
 * create_buff - creates a buffer in memory and sets to 0
 * @bytes: number of bytes to allocate for buffer
 *
 * Return: char pointer to beginning of buffer
 */
char *create_buff(unsigned int bytes)
{
	char *new_buff;
	int i;
	new_buff = malloc(bytes);

	if (!new_buff)
		return (NULL);
	for (i = 0; i < bytes; i++)
		new_buff[i] = 0;

	return (new_buff);
}

/**
 * buff_size_calc - calcs the maximum size needed for the buffer
 * @format: the type of data we need
 * @args: pointer to the list for the printf
 * Description: long description
 *
 * Return: add in what is supposed to be returned if anything
 */
t_buff *buff_size_calc(const char *format)
{
	t_buff *create;

	create = malloc(sizeof(t_buff));
	if (create == NULL)
		return (NULL);
	create->buffer = create_buff(1024);
	create->format = format;
	create->buff_len = 0;
	create->buff_loc = 0;
	create->form_loc = 0;
	return (create);
}
