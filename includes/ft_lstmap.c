/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorel <jmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:29:32 by jmorel            #+#    #+#             */
/*   Updated: 2022/01/12 09:29:07 by jmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* le but de map c'est d'appliquer a fonction f sur chaque element de la
nouvelle liste. La fonction del pour detruire le contenu si necessaire.
Donc tout d'abord on cree une nouvelle liste en appelant la fonction 
lstnew. On protege. Tant qu'il y a quelque chose dans la liste initiale on
va mettre on va mettre chaque elements de cette liste dans la nouvelle et s'il
y a plus rien a mettre on clear le reste en faisant delete et on conclut en
mettant le null en fin de liste pour conclure la liste chainee. Si on sort du
while et que les deux listes concordent on ajoutera un NULL comme next 
element */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*save;

	if (!lst || !f)
		return (0);
	new_list = ft_lstnew(f(lst->content));
	if (!new_list)
		return (0);
	save = new_list;
	lst = lst->next;
	while (lst)
	{
		new_list->next = ft_lstnew(f(lst->content));
		if (!new_list->next)
		{
			ft_lstclear(&save, del);
			return (0);
		}
		new_list = new_list->next;
		lst = lst->next;
	}
	new_list->next = NULL;
	return (save);
}
