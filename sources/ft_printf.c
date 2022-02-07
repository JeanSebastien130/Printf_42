/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorel <jmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:27:26 by jmorel            #+#    #+#             */
/*   Updated: 2022/01/20 11:05:57 by jmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_printf.h"
#include "../Libft/libft.h"

int	ft_format(va_list args, const char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_char(va_arg(args, int));
	else if (format == 's')
		len += ft_str(va_arg(args, char *));
	else if (format == 'p')
		len += ft_pointer_print(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		len += ft_nbr(va_arg(args, int));
	else if (format == 'u')
		len += ft_unsigned_print(va_arg(args, unsigned int), format);
	else if (format == 'x' || format == 'X')
		len += ft_hexa_print(va_arg(args, unsigned int), format);
	else if (format == '%')
		len += ft_percent();
	return (len);
}

int	ft_printf(const char *str, ...)
{	
	va_list	args;	
	int		len2print;
	int		i;

	va_start(args, str);
	len2print = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			len2print += ft_format(args, str[i + 1]);
			i++;
		}
		else
			len2print += ft_char(str[i]);
		i++;
	}
	va_end (args);
	return (len2print);
}
