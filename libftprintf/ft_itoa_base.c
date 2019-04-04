/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkellum <nkellum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 14:05:28 by nkellum           #+#    #+#             */
/*   Updated: 2019/04/04 14:04:30 by nkellum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

long long ft_pow(long long nb, int pow)
{
	if (pow == 0)
		return (1);
	else
		return (nb * ft_pow(nb, pow - 1));
}

char	*ft_itoa_base(long long value, int base, int lowercase)
{
	int		i;
	char	*nbr;
	int		neg;
	int hexneg;

	i = 1;
	hexneg = 0;
	neg = 0;
	if (value < 0)
	{
		if (base == 10)
			neg = 1;
		if(base == 16)
			hexneg = 1;
		value *= -1;
	}
	while (ft_pow(base, i) - 1 < value)
	{
		if(ft_pow(base, i) - 1 > 0 && ft_pow(base, i + 1) - 1 == -1)
		{
			i++;
			break;
		}
		i++;
	}
	nbr = (char*)malloc(sizeof(nbr) * i);
	nbr[i + neg] = '\0';

	while (i-- > 0)
	{

		nbr[i + neg] = (value % base) + (value % base > 9 ?
			 (lowercase ? 'a' - 10 : 'A' - 10) : '0');
		value = value / base;
	}

	if (neg)
		nbr[0] = '-';
	return (nbr);
}
