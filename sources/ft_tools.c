/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorel <jmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 09:21:31 by jmorel            #+#    #+#             */
/*   Updated: 2022/01/17 18:07:03 by jmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_printf.h"
#include "../Libft/libft.h"

int	ft_percent(void)
{
	write(1, "%", 1);
	return (1);
}

int	ft_char(char c)
{
	return (write(1, &c, 1));
}

int	ft_str(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_str ("(null)");
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_nbr(int n)
{
	int		len;
	char	*nbr;

	len = 0;
	nbr = ft_itoa(n);
	len = ft_str(nbr);
	free(nbr);
	return (len);
}
