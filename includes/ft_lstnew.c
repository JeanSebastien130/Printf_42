/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorel <jmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 10:01:26 by jmorel            #+#    #+#             */
/*   Updated: 2022/01/10 11:02:22 by jmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*newstr;

	newstr = malloc(sizeof(t_list));
	if (newstr == NULL)
		return (0);
	newstr->content = content;
	newstr->next = NULL;
	return (newstr);
}
