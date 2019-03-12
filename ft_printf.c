/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkellum <nkellum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 17:58:03 by nkellum           #+#    #+#             */
/*   Updated: 2019/03/11 15:01:38 by nkellum          ###   ########.fr       */
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

void print_string(char *fmt, char c)
{



}

void print_num(va_list ap, char *fmt, char c)
{
	int i;
	double d;
	float f;

	if(c == 'd')
	{
		i = va_arg(ap, int);
		//ft_putnbr(i);
	}



}

void analyse_format(va_list ap, char *fmt, char c)
{
	int i;
	char *str_formats = "csp";
	t_flags *flags;

	if((flags = malloc(sizeof(t_flags))) == NULL)
		return ;
	flags->fmt_str = ft_strsub(fmt, 0, ft_strchr(fmt, c) - fmt);
	flags->fmt_char = c;
	get_flags(flags);
	printf("%s\n", "ft_printf(\"%0+-10234.223#d\", num);");
	printf("field_length = %d\n", flags->field_length);
	printf("precision_val = %d\n", flags->precision_val);


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
		print_num(ap, fmt, c);
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
				analyse_format(ap, fmt, c);
			else
				ft_putchar(*fmt);
	  }
	  else
	  	//ft_putchar(*fmt);
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
	//ft_printf("this is a normal string but wait here comes %oh you missed it");
	//printf("%&d 00 0006#dの⛱\n", num);
	ft_printf("%0+-10234.223#d", num);
	//printf("[%0 50.f]\n", flt);


}
