/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkellum <nkellum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 17:58:03 by nkellum           #+#    #+#             */
/*   Updated: 2019/04/18 15:55:54 by nkellum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int contains(char *str, char c)
{
	int i;
	int num;

	i = 0;
	num = 0;
	while(str[i])
	{
		if(str[i] == c)
			num++;
		i++;
	}
	return (num);
}

char check_format(const char *fmt)
{
	int i;
	char *formats;
	char *flags;

	i = 0;
	formats = "cspdiouxXf%";
	flags = " .#0123456789-+hlL";
	while(fmt[i])
	{
		if(contains(formats, fmt[i]))
			return (fmt[i]);
		if(!contains(flags, fmt[i]))
			return ('$');
		i++;
	}
	if(contains("hlLjtzq", fmt[i - 1]))
	{
		//printf("sent invalid char to function\n");
		return ('$');
	}
	return ('\0');
}



void analyse_format(va_list ap, const char *fmt, char c, t_flags *flags)
{
	int i;
	char *str_formats;

	flags->fmt_str = ft_strsub(fmt, 0, ft_strchr(fmt, c) - fmt);
	flags->fmt_char = c;
	flags->h = contains(flags->fmt_str, 'h');
	flags->l = contains(flags->fmt_str, 'l');
	flags->L = contains(flags->fmt_str, 'L');
	get_flags(flags);
	i = 0;
	str_formats = "cs";
	if(contains(str_formats, c))
	{
		flags->is_str = 1;
		print_string(ap, flags);
	}
	else
	{
		flags->is_str = 0;
		print_num(ap, flags);
	}
	free(flags->fmt_str);
}

void print_dpercent_field(t_flags *flags)
{
	int i;

	i = 0;
	if(flags->left_adjustment)
		ft_putchar('%', flags);
	while(i < flags->field_length - 1)
	{
		if(flags->pad_zero)
			ft_putchar('0', flags);
		else
			ft_putchar(' ', flags);
		i++;
	}
	if(!flags->left_adjustment)
		ft_putchar('%', flags);
}

void get_dpercent_field(char *str, t_flags *flags)
{
	int i;

	i = 0;
	while(str[i] != '%')
	{
		if(str[i] == '0')
			flags->pad_zero = 1;
		if(str[i] == '.')
			flags->precision_dot = 1;
		if(str[i] == '-')
			flags->left_adjustment = 1;
		if(str[i] >= '1' && str[i] <= '9' && !flags->precision_dot)
		{
			flags->field_length = ft_atoi(str + i);
			break;
		}
		i++;
	}
	if(flags->left_adjustment && flags->pad_zero)
		flags->pad_zero = 0;
	print_dpercent_field(flags);
}

void print_invalid_fmt_field(t_flags *flags)
{
	int i;

	i = 0;
	if(!contains("hlLjtzq", flags->c) ||
	(contains("hlLjtzq", flags->c) && !flags->left_adjustment))
	{
		if(!contains("hlLjtzq", flags->c) && flags->left_adjustment)
			ft_putchar(flags->c, flags);
			while(i < flags->field_length - 1)
			{
				if(flags->pad_zero)
					ft_putchar('0', flags);
				else
					ft_putchar(' ', flags);
				i++;
			}
			if(!contains("hlLjtzq", flags->c) && !flags->left_adjustment)
				ft_putchar(flags->c, flags);
	}
}

int get_invalid_fmt_field(char *str, t_flags *flags)
{
	int i;

	i = 0;
	while(contains("-+#*01234564789. ", str[i]))
	{
		if(str[i] == '0')
			flags->pad_zero = 1;
		if(str[i] == '-')
			flags->left_adjustment = 1;
		if(str[i] == '.')
			flags->precision_dot = 1;
		if(str[i] >= '1' && str[i] <= '9' && !flags->precision_dot)
		{
			flags->field_length = ft_atoi(str + i);
			i += num_length(flags->field_length) - 1;
		}
		i++;
	}
	while(contains("hlLjtzq", str[i]))
		i++;
	flags->c = str[i];
	print_invalid_fmt_field(flags);
	return (i);
}

int ft_printf(const char *fmt, ...)
{
	va_list ap;
	int d;
	int chars_printed;
	char c;
	t_flags *flags;

	if((flags = malloc(sizeof(t_flags))) == NULL)
		return 0;
	init_flags(flags);

  va_start(ap, fmt);
  while (*fmt && !(ft_strlen(fmt) == 1 && fmt[0] == '%'))
  {
	  if(*fmt == '%')
	  {
		  	fmt++;
			c = check_format(fmt);
			if(c == '%')
			{
				get_dpercent_field(fmt, flags);
				fmt += ft_strchr(fmt, c) - fmt;
			}
			else if(c == '$')
			{
				fmt += get_invalid_fmt_field(fmt, flags);
			}
		  	else if(c != '\0')
			{
				analyse_format(ap, fmt, c, flags);
				fmt += ft_strchr(fmt, c) - fmt;
			}
			else
			{
				if(*fmt == ' ')
				{
					while(*(fmt + 1) == ' ')
						fmt++;
				}
				else
					ft_putchar(*fmt, flags);
			}
	  }
	  else
	  	ft_putchar(*fmt, flags);
	fmt++;
  }
	chars_printed = flags->chars_printed;
  	free(flags);
	va_end(ap);
	return (chars_printed);
}
