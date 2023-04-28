#include "main.h"

/**
 * _printf - function that produces output according to a format
 * @format: character string
 * Return: number of character printed
 */

int _printf(const char *format, ... )
{
  va_list arguments;
  const char *frmt;
  int i = 0;
  char c_buff;
  char *s_buff;

  va_start(arguments, format);

  for (frmt = format ; *frmt != '\0' ; frmt++)
    {
      if (*frmt != '%')
	{
	  write(1, frmt, 1);
	  i++;
	}
      else if (*(frmt+1) == '%')
	{
	  write(1, "%", 1);
	  i++;
	  frmt++;
	}
      else if (*(frmt+1) == 'c')
	{
	  c_buff = (char) va_arg(arguments, int);
	  write(1, &c_buff, 1);
	  i++;
	  frmt++;
	}
      else if (*(frmt+1) == 's')
	{
	  s_buff = va_arg(arguments, char*);
	  for (; *s_buff != '\0' ; s_buff++)
	    {
	      write(1, s_buff, 1);
	      i++;
	    }
	  frmt++;
	}
      else
	{
	  write(2, "error: unknown format specifier\n", 32);
	  va_end(arguments);
	  return -1;
	}
    }

  va_end(arguments);
  return i;
}
