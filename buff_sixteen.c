#include <stdio.h>
#include <stdarg.h>
#include "main.h"
#include <stdlib.h>

/**
* buff_sixteen - calcs the size needed for the buffer
* @args: pointer to the list_item we need to print
* Description:
*
* Return: will return a blank 4 for now.
*/
int buff_sixteen(va_list *args)
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
	while (c > 15)
	{
		c = c / 16;
		buffSize++;
	}

	return (buffSize);
}
