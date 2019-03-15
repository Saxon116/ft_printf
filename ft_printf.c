/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkellum <nkellum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 17:58:03 by nkellum           #+#    #+#             */
/*   Updated: 2019/03/15 11:29:16 by nkellum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int contains(char *str, char c)
{
	int i;

	i = 0;
	while(str[i])
	{
		if(str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char check_format(char *fmt)
{
	int i;
	int valid;
	char *formats;
	char *flags;

	i = 0;
	valid = 1;
	formats = "cspdiouxXf";
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



void analyse_format(va_list ap, char *fmt, char c)
{
	int i;
	char *str_formats;
	t_flags *flags;

	if((flags = malloc(sizeof(t_flags))) == NULL)
		return ;
	flags->fmt_str = ft_strsub(fmt, 0, ft_strchr(fmt, c) - fmt);
	flags->fmt_char = c;
	get_flags(flags);

	i = 0;
	str_formats = "csp";
	if(contains(str_formats, c))
	{
		flags->is_str = 1;
		// string!

	}
	else
	{
		flags->is_str = 0;
		print_num(ap, flags);
	}
}


void ft_printf(char *fmt, ...)
{
	va_list ap;
	int d;
	char c, *s;

  va_start(ap, fmt);
  while (*fmt)
  {
	  if(*fmt == '%')
	  {
		  *fmt++;
			c = check_format(fmt);
			if(*fmt == '%')
				ft_putchar('%');
		  	else if(c != '\0')
			{
				analyse_format(ap, fmt, c);
				fmt += ft_strchr(fmt, c) - fmt;
			}
			else
				ft_putchar(*fmt);
	  }
	  else
	  	ft_putchar(*fmt);
	*fmt++;
  }
    va_end(ap);
}


int main()
{
	char *str = "great im done with printf";
	int fieldwidth = 10;
	double flt = 1612.123456789;
	int num = 1612;

	printf("[%-20.10d]\n", 1612);
	ft_printf("[%-20.10d]\n", 1612);


}
