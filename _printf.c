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
	unsigned int i = 0, j, slen, perc = 0, m, n = 0, skip;
	va_list ap;
	char *tmp, *f;
	char ac[] = {'c', 's', '%'};
	m = strlen(format);
	f = malloc(m + 1);
	strcpy(f, format);

	va_start(ap, format);
	while (format && f[i])
	{
		skip = 0;
		tmp = malloc(1);
		if (f[i] == '%')
			perc += 1;
		if (i == 0)
		{
			if (f[i] != '%')
			{
				tmp[0] = f[i];
				n += 1;
				write(1, tmp, 1);
			}
		}
		else if (f[i] == '%' && f[i - 1] != '%' && i < m - 1)
		{
			for (j = 0; j < 3; j++)
			{
				if (f[i + 1] == ac[j])
				{
					skip = 1;
					break;
				}
			}
			if (!skip)
			{
				tmp[0] = f[i];
				write(1, tmp, 1);
			}
		}
		else
		{
			if (f[i - 1] == '%')
			{	
				switch (f[i])
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
						tmp = "%";
						if (perc % 2 == 0)
						{
							n += 1;
							write(1, tmp, 1);
						}
						else if (f[i + 1] != '%')
						{
							n += 1;
							write(1, tmp, 1);
							perc = 0;
						}
						break;
					default:
						tmp[0] = f[i];
						n += 1;
						write(1, tmp, 1);
						break;
				}
			}
			else
			{
				tmp[0] = f[i];
				n += 1;	
				write(1, tmp, 1);
			}
		}
		i++;
	}
	va_end(ap);
	return (n);
}
