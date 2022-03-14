#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>

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
char *(*type)(char*, va_list *);
} t_mod;

/**
* struct buffer_calc - data struct to help with buffer calc
* @symbol: selector type, %s=string, %c=char, %f=float, %i=integer etc.
* @type: pointer to function to calc specific data types
*
* Description:
*/
typedef struct buffer_calc
{
char *symbol;
int (*type)(va_list *);
} t_buff;

int _printf(const char *format, ...);
int _putchar(char c);
int _islower(int c);
int _isalpha(int c);
int _abs(int n);
int _isupper(int c);
int _isdigit(int c);
int _strlen(const char *s);
void _puts(char *s);
char *_strcpy(char *dest, const char *src);
int _atoi(char *s);
char *_strcat(char *dest, char *src);
char *_strncat(char *dest, char *src, int n);
char *_strncpy(char *dest, char *src, int n);
int _strcmp(char *s1, char *s2);
char *_memset(char *s, char b, unsigned int n);
void *_memcpy(void *dest, void *src, unsigned int n);
char *_strchr(char *s, char c);
unsigned int _strspn(char *s, char *accept);
char *_strpbrk(char *s, char *accept);
char *_strstr(char *haystack, char *needle);
char *_strdup(char *str);
char *print_char(char *format, va_list *var);
char *print_int(char *format, va_list *var);
char *print_string(char *format, va_list *var);
char *print_percent(char *format, va_list *var);
char *print_eight(char *format, va_list *var);
char *print_sixteen(char *format, va_list *var);
char *print_mod(char *format, va_list *var);
char *print_uns(char *format, va_list *var);
char *print_binary(char *format, va_list *var);
int buff_size_calc(const char *format, va_list *args);
int buff_string(va_list *args);
int buff_char(va_list *args);
int buff_int(va_list *args);
int buff_float(va_list *args);
int buff_eight(va_list *args);
int buff_sixteen(va_list *args);
void rev_string(char *s);
char *remove_char(char *format);

#endif /* MAIN_H */
