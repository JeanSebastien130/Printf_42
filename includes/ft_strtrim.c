/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorel <jmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:55:26 by jmorel            #+#    #+#             */
/*   Updated: 2022/01/17 16:37:10 by jmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 1. le sb est a 0 et tant
 que le mot existe et
que le caractere actuel est 
dans le charset on augmente sb. */
/* 2.le se demarre de la fin du mot on decrementera 
pour savoir plus tard de quelle base on doit
le sb pour le calcul du malloc. Donc tant que se est
 plus grand que sb sinon ca veut dire que
tous les elements font partis du charsetet que la
lettre fait partie du charset on decremente.*/
/* 3. Avec les informations dont on dispose 
on peut calculer le malloc.
4. On protege le malloc.
5. On reset le i a 0 pour creer le mot.
6. Tant que le sb est plus petit que se car on 
va incrementer sb jusqu'a ce qu'il atteignent
le prochain charset qui est a la fin de se.*/
/*7. On commence le string copy a partir de sb 
car ce qu'il y a avant est charset et on
incremente i et se.
8. dernier element du newstr est '\0' et on return le mot.
*/

#include "libft.h"

int	is_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*newstr;
	int		i;
	int		sb;
	int		se;

	sb = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[sb] && is_charset(s1[sb], (char *)set))
		sb++;
	se = ft_strlen(s1);
	while (se > sb && is_charset(s1[se - 1], (char *)set))
		se--;
	newstr = (char *)malloc(sizeof(char) * (se - sb + 1));
	if (!newstr)
		return (NULL);
	i = 0;
	while (sb < se)
	{
		newstr[i] = s1[sb];
		i++;
		sb++;
	}
	newstr[i] = 0;
	return (newstr);
}
