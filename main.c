#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>
#include <float.h>

int main()
{

	//
	// ft_printf("{%10h}\n", 0);
	// printf("{%10h}\n", 0);

	// ft_printf("\n{%-15tm}\n", 123);
	// printf("{%-15tm}\n", 123);
	//
	double george = 0.1;
	ft_printf("[%08.12f]\n", george);
	printf("[%08.12f]\n", george);
	// ft_printf("% 6d\n", -42);
	// printf("% 6d", -42);

}
