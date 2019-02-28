/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkellum <nkellum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:40:16 by nkellum           #+#    #+#             */
/*   Updated: 2019/02/28 14:34:55 by nkellum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFTPRINTF_H
# define FT_LIBFTPRINTF_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>


void				ft_putnbr(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);


#endif
