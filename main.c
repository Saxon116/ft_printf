#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>
#include <float.h>

int main()
{
	 double flt = 546186513.654984651;

	ft_printf("{%x}\n", 123456);
	printf("{%x}\n", 123456);

	ft_printf("{%05.Z}\n", 0);
	printf("{%05.Z}\n", 0);

	ft_printf("\n{%-15Z}\n", 123);
	printf("{%-15Z}\n", 123);

	ft_printf("\n{%10R}\n");
	printf("{%10R}\n");

}
