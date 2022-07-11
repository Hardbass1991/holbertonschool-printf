#include "main.h"
#include <stdio.h>
/**
 * print_number - prints an input int
 * @n: input int to print
 *
 * Return: number of characters printed
 */
int print_number(int n)
{
	int a = 0, i, j, _n = n, N = 0;
	int tens = 1;

	if (_n < 0)
	{
		N += 1;
		_putchar('-');
		_n *= (-1);
	}
	
	if (_n == 0)
	{
		N += 1;
		_putchar(_n + '0');
	}
	else
	{
		while (_n > 0)
		{
			_n = _n / 10;
			a++;
		}
		a -= 1;		
		if (n < 0)
			n *= (-1);

		if (n < 10)
		{
			N += 1;
			_putchar(n + '0');
		}
		else
		{
			for (i = a; i >= 0; i--)
			{
				for (j = 0; j < i; j++)
					tens *= 10;
				N += 1;
				_putchar((n / tens) + '0');
				n -= ((n / tens) * tens);
				tens = 1;
			}
		}
	}
	return (N);
}
