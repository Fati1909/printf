#include "main.h"

/**
 * int_to_str - function that converts an int to a string
 * @num: number to be converted
 * @str: string to convert the number
 * @base: the base of the number
 * Return: returns len
 */

int int_to_str(int num, char *str, int base)
{
int j = 0, k;
int is_negative = 0;

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

/**
 * _printfInts - function that handles the specifiers d & i
 * @format: character string
 * Return: returns the number of chars printed
 */

int _printfInts(const char *format, ...)
{
va_list arguments;
const char *frmt;
int i = 0;
char num_buff[32];

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
else if (*(frmt + 1) == 'd' || *(frmt + 1) == 'i')
{
int num = va_arg(arguments, int);
int len = int_to_str(num, num_buff, 10);
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
