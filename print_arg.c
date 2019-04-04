/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkellum <nkellum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 14:26:00 by nkellum           #+#    #+#             */
/*   Updated: 2019/04/04 19:21:34 by nkellum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void print_precision_str(t_flags *flags)
{
	int i;

	i = 0;
	while(i < flags->precision_val && flags->str[i])
	{
		ft_putchar(flags->str[i], flags);
		i++;
	}
}

void print_string_field(t_flags *flags)
{
	int i;

	i = 0;
	while(i < flags->field_length - (1 * (flags->fmt_char == 'c'))
	- (ft_strlen(flags->str) * (flags->precision_val == 0))
	- (flags->precision_val * (ft_strlen(flags->str) != 0)))
	{
		ft_putchar(' ', flags);
		i++;
	}
}

void print_string(va_list ap, t_flags *flags)
{
	int i;

	i = 0;
	if(flags->fmt_char == 's')
		flags->str = va_arg(ap, char *);
	if(flags->str == NULL)
	{
		ft_putstr("(null)", flags);
		return ;
	}
	if(flags->fmt_char == 'c')
		flags->c = va_arg(ap, int);
	if(!flags->left_adjustment)
		print_string_field(flags);
	if(flags->fmt_char == 's')
	{
		if(flags->precision_val > 0)
			print_precision_str(flags);
		else
			ft_putstr(flags->str, flags);
	}
	if(flags->fmt_char == 'c')
		ft_putchar(flags->c, flags);
	if(flags->left_adjustment)
		print_string_field(flags);
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

void print_precision(t_flags *flags)
{
	int i;

	i = 0;

	if(flags->is_neg)
	{
		ft_putchar('-', flags);
		flags->i = -flags->i;
	}
	else if(flags->positive_sign)
		ft_putchar('+', flags);
	while(i < flags->precision_val - num_length(flags->i))
	{
		ft_putchar('0', flags);
		i++;
	}
	ft_putnbr(flags->i, flags);
}

void print_field_sign(t_flags *flags)
{
	if(flags->pad_zero && !flags->precision_dot && flags->is_neg)
	{
		ft_putchar('-', flags);
		flags->i = -flags->i;
		flags->field_length--;
	}
	if(flags->positive_sign && !flags->precision_dot && !flags->is_neg
	&& flags->pad_zero)
		ft_putchar('+', flags);
	if(flags->space && flags->field_length <= (num_length(flags->i))
	&& flags->i > 0)
		ft_putchar(' ', flags);
}

void print_field(t_flags *flags)
{
	int i;

	i = 0;
	print_field_sign(flags);
	while(i < flags->field_length - (num_length(flags->i)
	+ (flags->precision_val - num_length(flags->i))
	* flags->precision_dot) - (flags->is_neg * flags->precision_dot)
	- (flags->positive_sign * !flags->is_neg))
	{
		if(flags->pad_zero && !flags->precision_dot)
			ft_putchar('0', flags);
		else
			ft_putchar(' ', flags);
		i++;
	}
	if(flags->positive_sign && !flags->precision_dot && !flags->is_neg
	&& !flags->pad_zero)
		ft_putchar('+', flags);
}

void apply_conversion_flags(va_list ap, t_flags *flags)
{
	if(flags->l != 0)
	{
		flags->i = va_arg(ap, unsigned long long int);
		if(flags->fmt_char == 'u')
			flags->i = (unsigned long long) flags->i;
	}
	else
	{
		flags->i = va_arg(ap, int);
		if(flags->fmt_char == 'u')
			flags->i = (unsigned int) flags->i;
	}
	if(flags->h != 0)
	{
		flags->i = (short int) flags->i;
		if(flags->fmt_char == 'u')
			flags->i = (unsigned short int) flags->i;
		if(flags->h >= 2)
		{
			flags->i = (char) flags->i;
			if(flags->fmt_char == 'u')
				flags->i = (unsigned char) flags->i;
		}
	}
}

int check_octal_format(t_flags *flags)
{
	int i;

	i = 0;
	if(flags->precision_dot && !flags->precision_val
		&& flags->i == 0 && !flags->hash)
	{
		while(i < flags->field_length)
		{
			ft_putchar(' ', flags);
			i++;
		}
		return (0);
	}
	return (1);
}

void print_octal(va_list ap, t_flags *flags)
{
	if(!check_octal_format(flags))
		return ;
	flags->i = va_arg(ap, unsigned long long);
	if(flags->h == 1)
		flags->i = (unsigned short int) flags->i;
	if(flags->h >= 2)
		flags->i = (unsigned char) flags->i;
	flags->i = ft_atoi_base(ft_itoa_base(flags->i, 8, 0), 10);
	if(flags->hash && !flags->precision_dot)
		flags->field_length--;
	if(!flags->left_adjustment)
		print_field(flags);
	if(flags->hash && !flags->precision_dot)
		ft_putchar('0', flags);
	if(flags->precision_dot)
		print_precision(flags);
	else
		ft_putnbr(flags->i, flags);
	if(flags->left_adjustment)
		print_field(flags);
}



void print_num(va_list ap, t_flags *flags)
{
	if(flags->fmt_char == 'd' || flags->fmt_char == 'i'
	|| flags->fmt_char == 'u')
	{
		apply_conversion_flags(ap, flags);
		if(flags->i < 0)
			flags->is_neg = 1;
		if(!flags->left_adjustment)
			print_field(flags);
		if(flags->precision_dot)
			print_precision(flags);
		else
			ft_putnbr(flags->i, flags);
		if(flags->left_adjustment)
			print_field(flags);
	}
	if(flags->fmt_char == 'o')
		print_octal(ap, flags);
	if(flags->fmt_char == 'x' || flags->fmt_char == 'X'
	|| flags->fmt_char == 'p')
		print_hex(ap, flags);
	if(flags->fmt_char == 'f')
	{
		flags->precision_val =
		flags->precision_dot ? flags->precision_val : 6;
		print_double(ap, flags);
	}
}
