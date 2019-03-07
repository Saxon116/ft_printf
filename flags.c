/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkellum <nkellum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 16:21:44 by nkellum           #+#    #+#             */
/*   Updated: 2019/03/07 17:42:53 by nkellum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_flags(t_flags *flags)
{
	flags->left_adjustment = 0;
	flags->positive_sign = 0;
	flags->space = 0;
	flags->pad_zero = 0;
	flags->hash = 0;
	flags->precision_dot = 0;
	flags->precision_val = 0;
	flags->field_length = 0;
	flags->field_length_val = 0;
}

void get_flags(t_flags flags)
{
	int i;

	i = 0;
	if(contains(flags->fmt_str, '-'))
		flags->left_adjustment = 1;
	if(contains(flags->fmt_str, '+'))
		flags->positive_sign = 1;
	if(contains(flags->fmt_str, ' '))
		flags->space = 1;
	if(contains(flags->fmt_str, '#'))
		flags->hash = 1;


}
