#include <stdio.h>
#include "ft_printf.h"

int main()
{
	int fieldwidth = 10;
	double flt = 15600000.4300465510;
	long long num = -92233724775808;
	//void *ptr = &flt;
	//char *str = ft_itoa_base(num, 16);
	//long long i = (char) num;
	//char *str = ft_itoa_base(4294843841, 8);
	//long long i = ft_atoi_base(ft_itoa_base(4294843841, 8), 10);
	//char *str =

	//printf(0"%s %010o\n", ft_itoa_base(num, 16), num);
	//ft_printf("12345678901234567890\n");
	//printf("%s", "abc");
	//printf("%.0%\n");
	//printf("%llx", 9223372036854775807);
	// printf("printf returned %d\n", printf("ft_printf %llx\n", num));
	// printf("ft_printf returned %d\n", ft_printf("ft_printf %llx\n", num));


	// if(num < -9223372036854775807)
	// 	printf("yay we can check this\n");
	ft_printf("%5lu\n", 4294967295);
	printf("%5lu\n", 4294967295);

}

// 18446744073709551615
// 9223372036854775808
