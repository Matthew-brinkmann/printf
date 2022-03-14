#include <stdio.h>
#include <stdarg.h>
#include "main.h"
#include <stdlib.h>

/**
* buff_eight - calcs the size needed for the buffer
* @args: pointer to the list_item we need to print
* Description: this seems redudant but the main use here
* is to remove the top element of the list.
* will use this funtion to handle flags if needed.
* Return: add in what is supposed to be returned if anything
*/
int buff_eight(va_list *args)
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
	while (c > 7)
	{
		c = c / 8;
		buffSize++;
	}

	return (buffSize);
}
