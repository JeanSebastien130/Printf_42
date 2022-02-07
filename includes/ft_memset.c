/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorel <jmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:06:49 by jmorel            #+#    #+#             */
/*   Updated: 2022/01/11 14:27:07 by jmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* on cree pointeur de p, p qui sera egal a ce qui pointe sur b ca sera un char
puis tant que la longueur est pas egale a 0 la lettre qui pointe sur p
est remplacee par le caractere c. Ensuite on return le mot p. */

#include "libft.h"

void	*ft_memset(void	*b, int c, size_t len)
{
	size_t			i;
	unsigned char	*p;

	p = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		p[i] = c;
		i++;
	}
	return (p);
}
