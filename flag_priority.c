/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_priority.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkellum <nkellum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 13:39:51 by nkellum           #+#    #+#             */
/*   Updated: 2019/04/15 14:43:45 by nkellum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void prioritize(t_flags *flags)
{

	if(flags->positive_sign && flags->space)
		flags->space = 0;
	if(flags->precision_dot && flags->pad_zero
		&& flags->fmt_char != 'c' && flags->fmt_char != 's')
		flags->pad_zero = 0;
	if(flags->pad_zero && flags->left_adjustment)
		flags->pad_zero = 0;
	if(flags->pad_zero && flags->left_adjustment)
		flags->pad_zero = 0;
	if(flags->fmt_char == 'u')
	{
		flags->space = 0;
		flags->positive_sign = 0;
	}

}
