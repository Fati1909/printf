#include "main.h"

/**
 * print_from_to - description
 * @start: starting address
 * @stop: stopping address
 * @except: except address
 * Return: num of bytes printed
 */

int print_from_to(char *start, char *stop, char *except)
{
	int s = 0;

	while (start <= stop)
	{
		if (start != except)
			s += _putchar(*start);
		start++;
	}
	return (s);
}

/**
 * print_rev - description
 * @ap: string
 * @params: parameters
 * Return: num bytes printed
 */

int print_rev(va_list ap, params_t *params)
{
	int len, s = 0;
	char *str = va_arg(ap, char *);
	(void)params;

	if (str)
	{
		for (len = 0; *str; str++)
			len++;
		str--;
		for (; len > 0; len--, str--)
			s += _putchar(*str);
	}
	return (s);
}


/**
 * print_rot13 - description
 * @ap: string
 * @params: parameters
 * Return: num of bytes printed
 */

int print_rot13(va_list ap, params_t *params)
{
	int i, index;
	int count = 0;
	char arr[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm"
		char *a = va_arg(ap, char *);
	(void)params;

	i = 0;
	index = 0;
	while (a[i])
	{
		if ((a[i] >= 'A' && a[i] <= 'Z')
				|| (a[i] >= 'a' && a[i] <= 'z'))
		{
			index = a[i] - 65;
			count += _putchar(arr[index]);
		}
		else
			count += _putchar(a[i]);
		i++;
	}
	return (count);
}
