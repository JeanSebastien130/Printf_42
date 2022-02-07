/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorel <jmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:10:37 by jmorel            #+#    #+#             */
/*   Updated: 2022/01/12 10:29:41 by jmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 1. on calcule la len en utilisant la fonction size qui calcule le nbr de
caractere que contient l'int. 
2. Ensuite on check le minimum int. 
3. On calcule le malloc et on securise
4. On fait passer le malloc calcule dans le convertnbr qui va faire passer l'int
en char.
5. On return la chaine.
*/
int	size(long long int n)
{
	if (n < 0)
		return (1 + size(-n));
	if ((n / 10) == 0)
		return (1);
	else
		return (1 + size(n / 10));
}

void	convertnbr(int n, char *nbr, int i)
{
	if (n < 0)
	{
		nbr[0] = '-';
		n *= -1;
	}
	if (n >= 10)
		convertnbr((n / 10), nbr, (i - 1));
	nbr[i] = (n % 10) + '0';
}

char	*ft_itoa(int n)
{
	char		*number;
	long int	len;

	len = size(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	number = (char *)malloc(sizeof(char) * len + 1);
	if (!number)
		return (NULL);
	number[len--] = '\0';
	convertnbr(n, number, len);
	return (number);
}
