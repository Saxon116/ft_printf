#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int main()
{
	int a;
	int *b;

	a = 42;
	b = &a;

	ft_printf("%d %s %c\n", 42, "Je corrige ton printf", 'c');
	printf("%d %s %c\n", 42, "Je corrige ton printf", 'c');

	ft_printf("\n%p\n", b);
	printf("%p\n", b);

	ft_printf("\n%i %o %u %x %X\n", a, a, -a, a, a);
	printf("%i %o %u %x %X\n", a, a, -a, a, a);

	ft_printf("\n[% d] [%12d] [%012d] [%.6d] [%+d] [%-12d] [%#x]\n",
	a,a,a,a,a,a,a);
	printf("\n[% d] [%12d] [%012d] [%.6d] [%+d] [%-12d] [%#x]\n",
	a,a,a,a,a,a,a);

	ft_printf("\n%d %ld %lld %hd %hhd\n", LONG_MAX, LONG_MAX, LONG_MAX, 420, 420);
	printf("%d %ld %lld %hd %hhd\n", LONG_MAX, LONG_MAX, LONG_MAX, 420, 420);

	ft_printf("\n%o %lo %llo %ho %hho\n", LONG_MAX, LONG_MAX, LONG_MAX, 420, 420);
	printf("%o %lo %llo %ho %hho\n", LONG_MAX, LONG_MAX, LONG_MAX, 420, 420);

	ft_printf("\n%x %lx %llx %hx %hhx\n", LONG_MAX, LONG_MAX, LONG_MAX, 420, 420);
	printf("%x %lx %llx %hx %hhx\n", LONG_MAX, LONG_MAX, LONG_MAX, 420, 420);

	return 0;
}
