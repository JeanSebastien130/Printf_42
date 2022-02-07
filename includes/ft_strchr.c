/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorel <jmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 10:23:42 by jmorel            #+#    #+#             */
/*   Updated: 2022/01/11 16:23:25 by jmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* tant qu'il y a mot cherche si la lettre du mot selectionne 
est egale a celle mise a la place de c. on incremente jusqua trouver 
si on trouve on returne le mot. Si on arrive au bout du mot on return 
le mot en entier */

#include "libft.h"

char	*ft_strchr(char	*s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (0);
}
