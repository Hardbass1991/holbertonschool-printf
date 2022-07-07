#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
/**
 * print_all - prints everyargument passe according to input format string
 * @format: input format string
 */
int _printf(const char *format, ...)
{
	int i = 0, slen, perc = 0;
	va_list ap;
	char *tmp;

	va_start(ap, format);
	while (format && format[i])
	{
		if (i = 0)
		{
			if (format[i] != '%')
				write(1, format[i], 1);
			else
				perc += 1;
		}
		else
		{
			if (format[i - 1] == '%')
			{	
				switch (format[i])
				{
					case 'c':
						write(1, va_arg(ap, int), 1);
						break;
					case 's':
						tmp = va_arg(ap, char*);
						slen = strlen(tmp);
						write(1, tmp, slen);
						break;
					case '%':
						perc += 1;
						if (perc % 2 == 0)
							write(1, '%', 1);
					default:
						write(1, format[i], 1);
				}
			}
			else
			{
				if (format[i] == '%')
					continue;
				write(1, format[i], 1);
			}
		}
		i++;
	}
	va_end(ap);
	printf("\n");
}
