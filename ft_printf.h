/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkellum <nkellum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 15:52:58 by nkellum           #+#    #+#             */
/*   Updated: 2019/03/11 14:29:45 by nkellum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include "libftprintf/libftprintf.h"

typedef	struct	s_flags
{
	char	*fmt_str;
	char	fmt_char;
	int	is_str;
	int	left_adjustment;
	int	positive_sign;
	int	space;
	int	pad_zero;
	int	hash;
	int	precision_dot;
	int	precision_val;
	int	field_length;
}		t_flags;

int contains(char *str, char c);
void get_flags(t_flags *flags);

#endif
