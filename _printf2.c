#include "main.h"

/**
 * _printf - function that produces output according to a format
 * @format: character string
 * Return: number of character printed
 */

int _printf(const char *format, ...)
{
	va_list ap;
	char *ptr, *start;
	int s = 0;
	params_t params = PARAMS_INIT;

	va_start(ap, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (ptr = (char *)format; *ptr; ptr++)
	{
		init_params(&params, ap);
		if (*ptr != '%')
		{
			s += _putchar(*ptr);
			continue;
		}
		start = ptr;
		ptr++;
		while (get_flag(p, &params))
		{
			ptr++;
		}
		ptr = get_width(p, &params, ap);
		ptr = get_precision(p, &params, ap);
		if (get_modifier(p, &params))
			ptr++;
		if (!get_specifier(p))
			s += print_from_to(start, p,
				params.l_modofier || params.h_modifier ? p - 1 : 0);
		else
		s += get_print_func(p, ap, &params);
	}
_putchar(BUF_FLUSH);
va_end(ap);
return (s);
}
