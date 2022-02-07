/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorel <jmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:03:51 by jmorel            #+#    #+#             */
/*   Updated: 2022/01/12 14:57:55 by jmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Split decoupe differente partie d'un fichier. On protege la fonction
ensuite on store dans la variable le nombre de mots qu'il y a dans le fichier
avec la fct nbrwords on set un count a 0 et le skip a 1 qu'on reset a 0 si on
pqsse d'un mot a l'qutre et on ajoute 1 au compte des mots sinon on garde le
skip a 1 et on incremente le mot dans tous les cas.
Ensuite on etabli notre malloc avec le la len qu'on a calcule dans la variable
num_word on protege si le malloc est mal calcule et s'il ne l'est pas on
applique la fonction ft_words avec le malloc comme premier parametre et la
variable num_word est la longueur du tableau */

#include "libft.h"

size_t	nbrwords(char const *s, char c)
{
	size_t	count;
	int		skip;

	count = 0;
	skip = 1;
	while (*s)
	{
		if (*s != c && skip)
		{
			skip = 0;
			count++;
		}
		else if (*s == c)
			skip = 1;
		s++;
	}
	return (count);
}

static void	ftwords(char **words, char const *s, char c, size_t nbrwords)
{
	char	*ptr;

	while (*s && *s == c)
		s++;
	while (nbrwords--)
	{
		ptr = ft_strchr((char *)s, c);
		if (ptr != NULL)
		{
			*words = ft_substr(s, 0, ptr - s);
			while (*ptr && *ptr == c)
				ptr++;
			s = ptr;
		}
		else
			*words = ft_substr(s, 0, ft_strlen(s) + 1);
		words++;
	}
	*words = NULL;
}

char	**ft_split(char const	*s, char const c)
{
	size_t	num_words;
	char	**words;

	if (s == NULL)
		return (NULL);
	num_words = nbrwords(s, c);
	words = malloc(sizeof(char **) * (num_words + 1));
	if (!words)
		return (NULL);
	ftwords(words, (char *)s, c, num_words);
	return (words);
}
