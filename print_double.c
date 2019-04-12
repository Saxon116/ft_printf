/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkellum <nkellum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 17:45:50 by nkellum           #+#    #+#             */
/*   Updated: 2019/04/11 17:30:56 by nkellum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_putdbl(t_flags *flags, int *array, long long num)
{
	int i;

	i = 0;
	ft_putnbr(num, flags);
	ft_putchar('.', flags);
	i = 0;
	while(i < flags->precision_val)
	{
		ft_putnbr(array[i], flags);
		i++;
	}
}

void apply_precision(int apply, t_flags *flags, int *array, long long num)
{
	int i;

	i = 0;
	if(apply)
	{
		array[flags->precision_val - 1]++;
		i = flags->precision_val - 1;
		while(i >= 0)
		{
			if(array[i] > 9)
			{
				array[i] = 0;
				if(i > 0)
					array[i - 1]++;
				else
					num++;
			}
			i--;
		}
	}
	ft_putdbl(flags, array, num);
}

void print_double(va_list ap, t_flags *flags)
{
 	long long num;
	int i;
	int array[flags->precision_val];
	double d;

	d = va_arg(ap, double);
	i = 0;
	num = (long long) d;
	double m = d - num;
	if(m < 0)
		m = -m;
	if(flags->precision_dot && flags->precision_val == 0)
	{
		m -= (int) m;
		m *= 10;
		if((int) m >= 5)
			num++;
		ft_putnbr(num, flags);
		return ;
	}
	while(i < flags->precision_val)
	{
		m *= 10;
		array[i] = (int) m;
		m -= (int) m;
		i++;
	}
	m *= 10;
	apply_precision((int) m >= 5, flags, array, num);
}
