/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkellum <nkellum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:40:16 by nkellum           #+#    #+#             */
/*   Updated: 2019/04/11 16:22:07 by nkellum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFTPRINTF_H
# define FT_LIBFTPRINTF_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include "../ft_printf.h"

char				*ft_strchr(const char *s, int c);
char				*ft_strsub(char const *s, unsigned int start,
	size_t len);
long long 			ft_atoi(const char *str);
int				ft_isdigit(int c);
char				*ft_itoa_base(long long value, int base,
	int lowercase);
char	*ft_utoa_base(unsigned long long value, int base,
	 int lowercase);
int				ft_strlen(char *str);
long long			ft_atoi_base(char *nb, int base);
long long			ft_pow(long long nb, int pow);





#endif
