/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_priority.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkellum <nkellum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 13:39:51 by nkellum           #+#    #+#             */
/*   Updated: 2019/04/04 18:16:46 by nkellum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void prioritize(t_flags *flags)
{

	if(flags->positive_sign && flags->space)
		flags->space = 0;
	if(flags->precision_dot && flags->pad_zero)
		flags->pad_zero = 0;
	if(flags->pad_zero && flags->left_adjustment)
		flags->pad_zero = 0;
	if(flags->pad_zero && flags->left_adjustment)
		flags->pad_zero = 0;
}
