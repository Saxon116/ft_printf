/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkellum <nkellum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:40:16 by nkellum           #+#    #+#             */
/*   Updated: 2019/03/27 20:32:57 by nkellum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFTPRINTF_H
# define FT_LIBFTPRINTF_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

void				ft_putnbr(long long n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
char				*ft_strchr(const char *s, int c);
char				*ft_strsub(char const *s, unsigned int start,
	size_t len);
long long 			ft_atoi(const char *str);
int				ft_isdigit(int c);
char				*ft_itoa_base(long long value, int base);
int				ft_strlen(char *str);
long long			ft_atoi_base(char *nb, int base);
long long			ft_pow(int nb, int pow);





#endif
