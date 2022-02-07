/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorel <jmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 11:56:59 by jmorel            #+#    #+#             */
/*   Updated: 2022/01/20 14:46:34 by jmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include "../Libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int				ft_prinstr(char *str);
int				ft_percent(void);
int				ft_char(char c);
int				ft_str(char *str);
int				ft_nbr(int n);
int				ft_format(va_list args, const char format);
int				ft_printf(const char *str, ...);
char			*ft_itoa(int n);
void			ft_hexa(unsigned int nb, const char format);
char			ft_hexa_print(unsigned int nb, const char format);
int				ft_hexa_len(unsigned int nb);
int				ft_unsigned_len(unsigned int nb);
void			ft_unsigned_convertnbr(long long n, char *nbr, int i);
char			ft_unsigned_print(unsigned int nb, const char format);
int				ft_ptr_len(unsigned long long int nb);
void			ft_ptr(unsigned long long nb);
char			ft_pointer_print(unsigned long long nb);
#endif