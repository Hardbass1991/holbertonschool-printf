#include "main.h"
#include <stdio.h>
/**
 * print_number - prints an input int
 * @n: input int to print
 *
 * Return: void
 */
void print_number(int n)
{
	int a = 0, i, j, _n = n;
	int tens = 1;

	if (_n < 0)
	{
		_putchar('-');
		_n *= (-1);
	}
	
	if (_n == 0)
		_putchar(_n + '0');
	else
	{
		while (_n > 0)
		{
			_n = _n / 10;
			a++;
		}
		a -= 1;

	/* "a" used to be the number of digits */
	/* Now it's the number of times the number can be integer-divided */
	/* by 10, without yielding 0 */
		
		if (n < 0)
			n *= (-1);

		if (n < 10)
			_putchar(n + '0');
		else
		{
			for (i = a; i >= 0; i--)
			{
				for (j = 0; j < i; j++)
					tens *= 10;
				_putchar((n / tens) + '0');
				n -= ((n / tens) * tens);
				tens = 1;
			}
		}
	}
}
