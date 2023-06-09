#include "main.h"

/**
 * _puts - description
 * @str: string
 * Return: void
 */

int _puts(char *str)
{
	char *p = str;
	
	while (*str)
		_putchar(*str++);
	return (str - p);
}

/**
 * _putchar - description
 * @c: char
 * Return: on success 1.
 * on error, -1 is returned, and errno is set appropriately.
 */

int _putchar(int c)
{
	static int i;
	static char buf[OUTPUT_BUF_SIZE];

	if (c == BUF_FLUSH || i >= OUTPUT_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}
