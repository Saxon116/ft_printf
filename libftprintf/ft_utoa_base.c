/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkellum <nkellum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 14:05:28 by nkellum           #+#    #+#             */
/*   Updated: 2019/04/11 16:20:52 by nkellum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

long long ft_upow(unsigned long long nb, int pow)
{
	if (pow == 0)
		return (1);
	else
		return (nb * ft_pow(nb, pow - 1));
}

char	*ft_utoa_base(unsigned long long value, int base, int lowercase)
{
	int		i;
	char	*nbr;

	i = 1;
	while (ft_upow(base, i) - 1 < value)
	{
		i++;
	}
	nbr = (char*)malloc(sizeof(nbr) * i);
	nbr[i] = '\0';
	while (i-- > 0)
	{

		nbr[i] = (value % base) + (value % base > 9 ?
			 (lowercase ? 'a' - 10 : 'A' - 10) : '0');
		value = value / base;
	}
	return (nbr);
}
