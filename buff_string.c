#include <stdio.h>
#include <stdarg.h>
#include "main.h"
#include <stdlib.h>

/**
 * buff_string - calcs the size of a string
 * @args: pointer to the list_item calc the size of
 * Description: long description
 *
 * Return: the size of the string in bytes
 */
int buff_string(va_list *args)
{
	char *c;
	int buffAdd = 0;

	c = va_arg(*args, char *);
	if (c == NULL || *c == '\0')
		return (0);
	return (buffAdd = _strlen(c));
}
