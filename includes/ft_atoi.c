/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorel <jmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:27:04 by jmorel            #+#    #+#             */
/*   Updated: 2022/01/11 14:33:15 by jmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Atoi classique seulement on prend en consideration le long long en incluant 
limits.h dans la libft et de la ligne 40 a 43 on s'occupe de l'int max et l'int
min.*/

#include "libft.h"

int	ft_atoi(const char *str)
{
	int						i;
	unsigned long long int	r;
	int						s;

	i = 0;
	r = 0;
	s = 1;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '-')
	{
		s *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		r = r * 10 + str[i++] - '0';
	if (r > LLONG_MAX && s == 1)
		return (-1);
	if (r - 1 > LLONG_MAX && s == -1)
		return (0);
	return (r * s);
}
