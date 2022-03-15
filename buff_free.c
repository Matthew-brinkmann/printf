#include <stdio.h>
#include <stdarg.h>
#include "main.h"
#include <stdlib.h>

/**
 * buff_free - free all the information stored in my data type
 * @buff: pointer to the buffer to free
 * Description: long description
 *
 * Return: nothing
 */
void _buff_free(t_buff *buff)
{
	if (buff != NULL)
	{
		free(buff->buffer);
		free(buff);
	}
}
