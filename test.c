#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    char *s = "hello";
    _printf("Hi guys,\n");
    _printf("hi guys %s bob\n", s);
    _printf("sup guys %o typop\n", 8);
    _printf("oct test: %x\n", 1553);
	_printf("int test %i\n", -1414);
	_printf("char test %s\n", 'C');
   return (0);
}
