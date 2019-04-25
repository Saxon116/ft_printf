/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkellum <nkellum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 15:26:07 by nkellum           #+#    #+#             */
/*   Updated: 2019/04/25 18:45:37 by nkellum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>
#include <float.h>

int	main(void)
{
	double d;

	d = -1.42567;
	ft_printf("%.5f\n", d);
	printf("%.5f\n", d);
}
