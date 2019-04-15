/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkellum <nkellum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 17:58:03 by nkellum           #+#    #+#             */
/*   Updated: 2019/04/15 16:38:52 by nkellum          ###   ########.fr       */
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
	int valid;
	char *formats;
	char *flags;

	i = 0;
	valid = 1;
	formats = "cspdiouxXf%";
	flags = " .#0123456789-+hl";
	while(fmt[i] && valid)
	{
		if(contains(formats, fmt[i]))
			return (fmt[i]);
		if(!contains(flags, fmt[i]))
			return ('\0');
		i++;
	}
	return ('\0');
}



void analyse_format(va_list ap, const char *fmt, char c, t_flags *flags)
{
	int i;
	char *str_formats;

	init_flags(flags);
	flags->fmt_str = ft_strsub(fmt, 0, ft_strchr(fmt, c) - fmt);
	flags->fmt_char = c;
	flags->h = contains(flags->fmt_str, 'h');
	flags->l = contains(flags->fmt_str, 'l');
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

void print_dpercent_field(int pad_zero, int field_length, t_flags *flags)
{
	int i;

	i = 0;
	while(i < field_length - 1)
	{
		if(pad_zero)
			ft_putchar('0', flags);
		else
			ft_putchar(' ', flags);
		i++;
	}
}

void get_dpercent_field(char *str, t_flags *flags)
{
	int pad_zero;
	int i;
	int field_length;

	field_length = 0;
	i = 0;
	pad_zero = 0;
	while(str[i] != '%' || (str[i] <= 'a' && str[i] >= 'z'
&& str[i] <= 'A' && str[i] >= 'Z'))
	{
		if(str[i] == '0')
			pad_zero = 1;
		if(str[i] >= '1' && str[i] <= '9')
		{
			field_length = ft_atoi(str + i);
			break;
		}
		i++;
	}
	print_dpercent_field(pad_zero, field_length, flags);
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
	flags->chars_printed = 0;

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
				ft_putchar('%', flags);
				fmt += ft_strchr(fmt, c) - fmt;
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
