#include <stdio.h>
#include <stdarg.h>
#include "main.h"
#include <stdlib.h>

/**
* buff_char - calcs the size needed for the buffer
* @args: pointer to the list_item we need to print
* Description: this seems redudant but the main use here
* is to remove the top element of the list.
* Return: add in what is supposed to be returned if anything
*/
int buff_char(va_list *args)
{
	char c;

	c = va_arg(*args, int);
	if (c == '\0')
		return (0);
	return (1);
}
