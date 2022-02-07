/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorel <jmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:54:19 by jmorel            #+#    #+#             */
/*   Updated: 2022/01/18 18:30:59 by jmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_printf.h"
#include "../Libft/libft.h"
#include <stdio.h>

int	ft_unsigned_len(unsigned int nb)
{
	int	len;

	len = 0;
	while (nb != 0)
	{
		len++;
		nb = nb / 10;
	}
	return (len);
}

void	ft_unsigned_nbr(long long n)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", 1);
	else
	{
		if (n < 0)
		{
			ft_putchar_fd('-', 1);
			n *= -1;
		}
		if (n / 10)
			ft_unsigned_nbr(n / 10);
		ft_putchar_fd(n % 10 + '0', 1);
	}
}

char	ft_unsigned_print(unsigned int nb, const char format)
{
	if (nb == 0)
		return (write(1, "0", 1));
	else
		ft_unsigned_nbr(nb);
	return (ft_unsigned_len(nb));
}
