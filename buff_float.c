#include <stdio.h>
#include <stdarg.h>
#include "main.h"
#include <stdlib.h>

/**
 * buff_float - calcs buffer size needed for a float.
 * @args: pointer to the list_item we need to print
 * Description: buffSize starts at 8 to allow for
 * number + decimalpoint + 6 decimal places.
 * Return: add in what is supposed to be returned if anything
 */
int buff_float(va_list *args)
{
	float c;
	int buffSize = 8;

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
