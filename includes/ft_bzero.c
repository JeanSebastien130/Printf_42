/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorel <jmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:15:20 by jmorel            #+#    #+#             */
/*   Updated: 2022/01/11 14:34:54 by jmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* mets à 0 octets les n premiers octets du bloc pointé par s */

#include "libft.h"

void	ft_bzero(void	*s, size_t	n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n--)
	{
		*p = '\0';
		p++;
	}
}
