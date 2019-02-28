/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkellum <nkellum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 17:58:03 by nkellum           #+#    #+#             */
/*   Updated: 2019/02/28 22:54:34 by nkellum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "libftprintf/libftprintf.h"

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

void analyse_format(char *fmt, char c)
{


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
				printf("valid format and flags\n");
				analyse_format(fmt, c);
			}
			else
			{
				printf("invalid format and flags\n");
				//ft_putchar(*fmt);
			}
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
	//ft_printf("%.5f", str, str);
	//printf("%&d 00 0006#dの⛱\n", num);
	printf("%-10d\n", num);

}
