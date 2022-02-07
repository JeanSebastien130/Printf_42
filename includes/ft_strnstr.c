/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorel <jmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 11:29:59 by jmorel            #+#    #+#             */
/*   Updated: 2022/01/11 12:15:18 by jmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char	*to_find, size_t len)
{
	size_t	i;
	size_t	j;
	char	*strnew;
	char	*to_findnew;

	strnew = (char *)str;
	to_findnew = (char *)to_find;
	j = 0;
	i = 0;
	if (to_findnew[i] == '\0')
		return (strnew);
	while (strnew[i] != '\0')
	{
		j = 0;
		while (strnew[i + j] == to_findnew[j])
		{
			if (to_findnew[j + 1] == '\0' && (i + j) < len)
				return (&strnew[i]);
			j++;
		}
		i++;
	}
	return (0);
}
