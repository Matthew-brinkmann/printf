#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>

#define MAX_BUFF 1024

/**
* struct buffer_calc - data struct to help with buffer calc
* @buffer: buffer to hold string
* @buff_len: length of the buffer
* @buff_loc: the current location of the pointer in the string.
* @print_char: the char to store in the buffer
* @print_int: the int to store in the buffer
* @flag: either a -1 or 1 depending on how the int needs to calculate.
* @format: copy of original format
* @form_loc: pointer to the place in the format we are.
* Description: all the data types for my bufer.
*/
typedef struct buffer_calc
{
	char *buffer;
	int buff_len;
	int buff_loc;
	/* original format info*/
	const char* format;
	int form_loc;
} t_buff;

/**
* struct modifier - holds my selector and pointer to function
* @symbol: selector type, %s=string, %c=char, %f=float, %i=integer etc.
* @type: pointer to function to print statement
*
* Description:
*/
typedef struct modifier
{
char *symbol;
t_buff *(*type)(t_buff*, va_list *);
} t_mod;

int _printf(const char *format, ...);
int _putchar(char c);
int _strlen(const char *s);
void _puts(char *s);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, char *src);
char *print_u_sixteen(char *format, va_list *var);
t_buff *print_char(t_buff *b_info, va_list *var);
t_buff *print_int(t_buff *b_info, va_list *var);
t_buff *print_string(t_buff *b_info, va_list *var);
char *print_percent(char *format, va_list *var);
char *print_eight(char *format, va_list *var);
char *print_sixteen(char *format, va_list *var);
char *print_ptr(char *format, va_list *var);
t_buff *print_mod(va_list *var, t_buff *b_info);
char *print_uns(char *format, va_list *var);
char *print_binary(char *format, va_list *var);
t_buff *buff_size_calc(const char *format);
void _buff_free(t_buff *buff);
int buff_char(va_list *args);
int buff_int(va_list *args);
int buff_float(va_list *args);
int buff_eight(va_list *args);
int buff_sixteen(va_list *args);
int buff_ptr(va_list *args);
void rev_string(char *s);
char *remove_char(char *format);

#endif /* MAIN_H */
