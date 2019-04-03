/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkellum <nkellum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 17:45:50 by nkellum           #+#    #+#             */
/*   Updated: 2019/04/03 18:33:26 by nkellum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_putdbl(int precision, int *array, int num)
{
	int i;

	i = 0;
	ft_putnbr(num);
	ft_putchar('.');
	i = 0;
	while(i < precision)
	{
		ft_putnbr(array[i]);
		i++;
	}
}

void apply_precision(int apply, int precision, int *array, int num)
{
	int i;

	i = 0;
	if(apply)
	{
		array[precision - 1]++;
		i = precision - 1;
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
	ft_putdbl(precision, array, num);
}

void print_double(va_list ap, t_flags *flags)
{
 	int num;
	int i;
	int array[flags->precision_val];
	double d;

	d = va_arg(ap, double);
	i = 0;
	num = (int) d;
	if(flags->precision_val == 0)
	{
		ft_putnbr(num);
		return ;
	}
	double m = d - num;
	if(m < 0)
		m = -m;
	while(i < flags->precision_val)
	{
		m *= 10;
		array[i] = (int) m;
		m -= (int) m;
		i++;
	}
	m *= 10;
	apply_precision((int) m >= 5, flags->precision_val, array, num);
}
