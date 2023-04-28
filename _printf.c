
#include "main.h"

/**
 * _printf - function that produces output according to a format
 * @format: character string
 * Return: number of character printed
 */

int int_to_str(int num, char *str, int base)
{
int j = 0;
int is_negative = 0;
int k;

if (num == 0)
{
str[j++] = '0';
str[j] = '\0';
return (1);
}
if (num < 0 && base == 10)
{
is_negative = 1;
num = -num;
}
while (num != 0)
{
int mod = num % base;
str[j++] = (mod > 9) ? (mod - 10) + 'a' : mod + '0';
num /= base;
}
if (is_negative)
{
str[j++] = '-';
}
str[j] = '\0';
k = j;
j = 0;
while (j < k / 2)
{
char t = str[j];
str[j] = str[k - j - 1];
str[k - j - 1] = t;
j++;
}
return (k);
}

int _printf(const char *format, ...)
{
va_list arguments;
const char *frmt;
int i = 0;
char c_buff, *s_buff, num_buff[32];
va_start(arguments, format);
for (frmt = format ; *frmt != '\0' ; frmt++)
{
if (*frmt != '%')
{
write(1, frmt, 1);
i++;
}
else if (*(frmt + 1) == '%')
{
write(1, "%", 1);
i++;
frmt++;
}
else if (*(frmt + 1) == 'c')
{
c_buff = (char) va_arg(arguments, int);
write(1, &c_buff, 1);
i++;
frmt++;
}
else if (*(frmt + 1) == 's')
{
s_buff = va_arg(arguments, char*);
for ( ; *s_buff != '\0' ; s_buff++)
{
write(1, s_buff, 1);
i++;
}
frmt++;
}
else if (*(frmt + 1) == 'd' || *(frmt + 1) == 'i')
{
int num = va_arg(arguments, int), len = int_to_str(num, num_buff, 10);
write(1, num_buff, len);
i += len;
frmt++;
}
else
{
write(2, "error: unknown format specifier\n", 32);
va_end(arguments);
return (-1);
}
}
va_end(arguments);
return (i);
}
