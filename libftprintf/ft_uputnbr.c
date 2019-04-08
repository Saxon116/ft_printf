/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uputnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkellum <nkellum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 10:40:08 by nkellum           #+#    #+#             */
/*   Updated: 2019/04/08 13:32:36 by nkellum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_uputnbr(unsigned long long n, t_flags *flags, int isneg)
{
	if (isneg)
		ft_putchar('-', flags);
	if (n >= 10)
		ft_putnbr(n / 10, flags);
	ft_putchar((n % 10) + '0', flags);
}
