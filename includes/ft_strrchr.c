/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorel <jmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 09:59:41 by jmorel            #+#    #+#             */
/*   Updated: 2022/01/11 14:28:50 by jmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* meme logique que le strchr sauf qu'ici on cherche 
la position du dernier caractere ou il y a le c que
l'on cherche. Ensuite une fois spotted on return last pos
et la fin du mot */

#include "libft.h"

char	*ft_strrchr(char *s, int c)
{
	char	*last_pos;

	last_pos = 0;
	while (*s)
	{
		if (*s == (unsigned char)c)
			last_pos = (char *)s;
		s++;
	}
	if (last_pos)
		return (last_pos);
	if ((unsigned char)c == '\0')
		return (s);
	return (0);
}
