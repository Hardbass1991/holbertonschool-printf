#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
/**
 * print_all - prints everyargument passe according to input format string
 * @format: input format string
 */
int _printf(const char *format, ...)
{
	int i = 0, slen, perc = 0, n = 0;
	va_list ap;
	char *tmp;

	va_start(ap, format);
	while (format && format[i])
	{
		if (i == 0)
		{
			if (format[i] != '%')
			{
				tmp[0] = format[i];
				n += 1;
				write(1, tmp, 1);
			}
			else
				perc += 1;
		}
		else
		{
			printf("p1");
			if (format[i - 1] == '%')
			{	
				switch (format[i])
				{
					case 'c':
						tmp[0] = va_arg(ap, int);
						n += 1;
						write(1, tmp, 1);
						break;
					case 's':
						tmp = va_arg(ap, char*);
						slen = strlen(tmp);
						n += 1;
						write(1, tmp, slen);
						break;
					case '%':
						perc += 1;
						if (perc % 2 == 0)
						{
							tmp = "%";
							n += 1;
							write(1, tmp, 1);
						}
						break;
					default:
						tmp[0] = format[i];
						n += 1;
						write(1, tmp, 1);
						break;
				}
			}
			else
			{
				tmp[0] = format[i];
				n += 1;	
				write(1, tmp, 1);
			}
		}
		i++;
	}
	va_end(ap);
	printf("\n");
	return (n);
}
