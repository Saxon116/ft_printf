/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkellum <nkellum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 14:26:00 by nkellum           #+#    #+#             */
/*   Updated: 2019/03/12 14:29:26 by nkellum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void print_string(t_flags *flags)
{



}

void print_num(va_list ap, t_flags *flags)
{
	int i;
	double d;
	float f;

	if(flags->fmt_char == 'd')
	{
		i = va_arg(ap, int);
		//ft_putnbr(i);
	}



}
