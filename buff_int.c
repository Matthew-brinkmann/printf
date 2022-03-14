#include <stdio.h>
#include <stdarg.h>
#include "main.h"
#include <stdlib.h>

/**
 * buff_int - calcs size needed for the buffer
 * @args: pointer to the list_item we need to calc
 * Description: long description
 *
 * Return: add in what is supposed to be returned if anything
 */
int buff_int(va_list *args)
{
	int c, buffSize = 1;

	c = va_arg(*args, int);
	if (c < 0)
	{
		/**
		 * change the negative to positive and
		 * add 1 to buffSize to allow for - sign
		 */
		c = c * -1;
		buffSize++;
	}
	while (c > 9)
	{
		c = c / 10;
		buffSize++;
	}

	return (buffSize);
}
