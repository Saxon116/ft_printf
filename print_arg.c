/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkellum <nkellum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 14:26:00 by nkellum           #+#    #+#             */
/*   Updated: 2019/03/29 14:26:04 by nkellum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void print_precision_str(char *str, int precision)
{
	int i;

	i = 0;
	while(i < precision && str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void print_string(va_list ap, t_flags *flags)
{
	int i;

	i = 0;
	if(flags->fmt_char == 's')
		flags->str = va_arg(ap, char *);
	if(flags->fmt_char == 'c')
		flags->c = va_arg(ap, int);
	while(i < flags->field_length - (1 * (flags->fmt_char == 'c'))
	- (ft_strlen(flags->str) * (flags->precision_val == 0))
	- flags->precision_val)
	{
		ft_putchar(' ');
		i++;
	}
	i = 0;
	if(flags->fmt_char == 's')
	{
		if(flags->precision_val > 0)
			print_precision_str(flags->str, flags->precision_val);
		else
			ft_putstr(flags->str);
	}
	if(flags->fmt_char == 'c')
		ft_putchar(flags->c);
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
		ft_putchar('-');
		flags->i = -flags->i;
	}
	else if(flags->positive_sign)
		ft_putchar('+');
	while(i < flags->precision_val - num_length(flags->i))
	{
		ft_putchar('0');
		i++;
	}
	ft_putnbr(flags->i);
}

void print_field(t_flags *flags)
{
	int i;

	i = 0;
	if(flags->pad_zero && !flags->precision_dot && flags->is_neg)
	{
		ft_putchar('-');
		flags->i = -flags->i;
		flags->field_length--;
	}
	if(flags->positive_sign && !flags->precision_dot && !flags->is_neg
	&& flags->pad_zero)
		ft_putchar('+');
	if(flags->space && flags->field_length <= (num_length(flags->i)))
		ft_putchar(' ');
	while(i < flags->field_length - (num_length(flags->i)
	+ (flags->precision_val - num_length(flags->i))
	* flags->precision_dot) - (flags->is_neg * flags->precision_dot)
	- (flags->positive_sign * !flags->is_neg))
	{
		if(flags->pad_zero && !flags->precision_dot)
			ft_putchar('0');
		else
			ft_putchar(' ');
		i++;
	}
	if(flags->positive_sign && !flags->precision_dot && !flags->is_neg
	&& !flags->pad_zero)
		ft_putchar('+');
}

void apply_conversion_flags(va_list ap, t_flags *flags)
{
	if(flags->l != 0)
	{
		flags->i = va_arg(ap, long long);
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

void print_octal(va_list ap, t_flags *flags)
{
	flags->i = va_arg(ap, unsigned long long);
	if(flags->h == 1)
		flags->i = (unsigned short int) flags->i;
	if(flags->h >= 2)
		flags->i = (unsigned char) flags->i;
	flags->i = ft_atoi_base(ft_itoa_base(flags->i, 8, 0), 10);
	if(!flags->left_adjustment)
		print_field(flags);
	if(flags->precision_dot)
		print_precision(flags);
	else
		ft_putnbr(flags->i);
	if(flags->left_adjustment)
		print_field(flags);
}

void print_field_hex(t_flags *flags, int length)
{
	int i = 0;

	i = 0;
	while(i < (flags->field_length - length
		- flags->precision_dot * (flags->precision_val - length)))
	{
		if(flags->pad_zero)
			ft_putchar('0');
		else
			ft_putchar(' ');
		i++;
	}
}

void print_precision_hex(t_flags *flags, int length)
{
	int i;

	i = 0;
	while(i < flags->precision_val - length)
	{
		ft_putchar('0');
		i++;
	}
}


void print_hex(va_list ap, t_flags *flags)
{
	int length;

	void *ptr;
	if(flags->fmt_char == 'p')
	{
		ptr = va_arg(ap, void *);
		flags->i = (long long) ptr;
	}
	else
		flags->i = va_arg(ap, unsigned long long);
	if(flags->h == 1 && flags->fmt_char != 'p')
		flags->i = (unsigned short int) flags->i;
	if(flags->h >= 2 && flags->fmt_char != 'p')
		flags->i = (char) flags->i;
	length = ft_strlen(ft_itoa_base(flags->i, 16, 0));
	if(flags->fmt_char == 'p')
		length += 2;
	if(!flags->left_adjustment)
		print_field_hex(flags, length);
	if(flags->fmt_char == 'p')
		ft_putstr("0x");
	print_precision_hex(flags, length);
	if(flags->fmt_char == 'x' || flags->fmt_char == 'p')
		ft_putstr(ft_itoa_base(flags->i, 16, 1));
	else
		ft_putstr(ft_itoa_base(flags->i, 16, 0));
	if(flags->left_adjustment)
		print_field_hex(flags, length);
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
			ft_putnbr(flags->i);
		if(flags->left_adjustment)
			print_field(flags);
	}
	if(flags->fmt_char == 'o')
		print_octal(ap, flags);
	if(flags->fmt_char == 'x' || flags->fmt_char == 'X'
	|| flags->fmt_char == 'p')
		print_hex(ap, flags);
}
