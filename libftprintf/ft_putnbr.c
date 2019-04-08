/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkellum <nkellum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 10:40:08 by nkellum           #+#    #+#             */
/*   Updated: 2019/04/08 13:15:05 by nkellum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr(long long n, t_flags *flags)
{
	if (n < 0)
	{
		ft_putchar('-', flags);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr(n / 10, flags);
	ft_putchar((n % 10) + '0', flags);
}
