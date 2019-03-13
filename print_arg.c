/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkellum <nkellum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 14:26:00 by nkellum           #+#    #+#             */
/*   Updated: 2019/03/13 18:08:44 by nkellum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void print_string(t_flags *flags)
{



}

int num_length(int num)
{
	int i;

	i = 0;
	if(num < 0)
	{
		num = -num;
		i++;
	}
	while(num /= 10)
		i++;
	i++;
	return (i);
}

void print_plusorspace(t_flags *flags)
{


}

void print_precision(t_flags *flags)
{
	int i;

	i = 0;
	if(flags->fmt_char == 'd')
	{
		if(flags->is_neg)
		{
			ft_putchar('-');
			flags->i = -flags->i;
		}
		while(i < flags->precision_val - num_length(flags->i))
		{
			ft_putchar('0');
			i++;
		}
		ft_putnbr(flags->i);
	}
}

void print_field(t_flags *flags)
{
	int i;

	i = 0;
	//printf("%d\n", flags->field_length);
	if(flags->pad_zero && !flags->precision_dot && flags->is_neg)
	{
		ft_putchar('-');
		flags->i = -flags->i;
		flags->field_length--;
	}
	while(i < flags->field_length - (num_length(flags->i)
	+ (flags->precision_val - num_length(flags->i))
	* flags->precision_dot) - (flags->is_neg * flags->precision_dot))
	{
		if(flags->pad_zero && !flags->precision_dot)
			ft_putchar('0');
		else
			ft_putchar(' ');
		i++;
	}



}

void print_num(va_list ap, t_flags *flags)
{


	if(flags->fmt_char == 'd')
	{
		flags->i = va_arg(ap, int);
		if(flags->i < 0)
			flags->is_neg = 1;
		print_field(flags);
		if(flags->precision_dot)
			print_precision(flags);
		else
			ft_putnbr(flags->i);

	}



}
