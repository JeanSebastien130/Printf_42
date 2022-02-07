/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorel <jmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 12:38:53 by jmorel            #+#    #+#             */
/*   Updated: 2022/01/11 14:54:53 by jmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* examine les n premiers octets de la zone mémoire pointée par s à la 
recherche du caractère c. Le premier octet correspondant à c arrête l'opération.
*/
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)s;
	i = 0;
	if (c == 0 && n == 0)
		return (NULL);
	while (i < n)
	{
		if (*str == (unsigned char)c)
			return (str);
		str++;
		i++;
	}
	if ((unsigned char)c == '\0')
		return (str);
	return (0);
}
