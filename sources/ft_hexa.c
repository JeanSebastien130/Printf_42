/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorel <jmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 09:47:02 by jmorel            #+#    #+#             */
/*   Updated: 2022/01/20 10:08:43 by jmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_printf.h"

int	ft_hexa_len(unsigned int nb)
{
	int	len;

	len = 0;
	while (nb != 0)
	{
		len++;
		nb = nb / 16;
	}
	return (len);
}

void	ft_hexa(unsigned int nb, const char format)
{
	if (nb >= 16)
	{
		ft_hexa(nb / 16, format);
		ft_hexa(nb % 16, format);
	}
	else
	{
		if (nb <= 9)
			ft_putchar_fd((nb + '0'), 1);
		else if (format == 'x')
			ft_putchar_fd((nb - 10 + 'a'), 1);
		else if (format == 'X')
			ft_putchar_fd((nb - 10 + 'A'), 1);
	}
}

char	ft_hexa_print(unsigned int nb, const char format)
{
	if (nb == 0)
		return (write(1, "0", 1));
	else
		ft_hexa(nb, format);
	return (ft_hexa_len(nb));
}
