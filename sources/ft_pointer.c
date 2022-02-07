/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorel <jmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 10:10:02 by jmorel            #+#    #+#             */
/*   Updated: 2022/01/20 14:45:57 by jmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_printf.h"
#include "../Libft/libft.h"

int	ft_ptr_len(unsigned long long int nb)
{
	int	len;

	len = 0;
	while (nb != 0)
	{
		len++;
		nb = (nb / 16);
	}
	return (len);
}

void	ft_ptr(unsigned long long nb)
{	
	if (nb >= 16)
	{
		ft_ptr(nb / 16);
		ft_ptr(nb % 16);
	}
	else
	{
		if (nb <= 9)
			ft_putchar_fd(nb + '0', 1);
		else
			ft_putchar_fd((nb - 10 + 'a'), 1);
	}
}

char	ft_pointer_print(unsigned long long nb)
{
	int	len;

	len = 0;
	len += write(1, "0x", 2);
	if (nb == 0)
		len += write(1, "0", 1);
	else
	{
		ft_ptr(nb);
		len += ft_ptr_len(nb);
	}
	return (len);
}
