/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkellum <nkellum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 15:52:58 by nkellum           #+#    #+#             */
/*   Updated: 2019/03/15 18:08:17 by nkellum          ###   ########.fr       */
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
	int	is_neg;
	int	left_adjustment;
	int	positive_sign;
	int	space;
	int	pad_zero;
	int	hash;
	int	precision_dot;
	int	precision_val;
	int	field_length;
	int	h;
	int	l;
	int	L;
	long long	i;
	double	d;
	float	f;
}		t_flags;

int contains(char *str, char c);
void get_flags(t_flags *flags);
void print_num(va_list ap, t_flags *flags);

#endif
