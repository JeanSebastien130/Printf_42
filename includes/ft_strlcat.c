/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorel <jmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 18:20:10 by jmorel            #+#    #+#             */
/*   Updated: 2022/01/12 16:29:47 by jmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlength(const char	*str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcat(char	*dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	destl;
	size_t	srcl;

	destl = ft_strlength(dest);
	srcl = ft_strlength(src);
	i = ft_strlength(dest);
	j = 0;
	if (size < 1)
		return (srcl + size);
	while (i < size - 1 && src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	if (size < destl)
		return (srcl + size);
	else
		return (srcl + destl);
}
