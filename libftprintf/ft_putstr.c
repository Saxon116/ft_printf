/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkellum <nkellum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 10:45:59 by nkellum           #+#    #+#             */
/*   Updated: 2019/04/04 15:15:46 by nkellum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putstr(char const *s, t_flags *flags)
{
	int i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		ft_putchar(s[i], flags);
		i++;
	}
}
