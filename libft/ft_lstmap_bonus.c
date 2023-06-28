/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anollero <anollero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:33:10 by anollero          #+#    #+#             */
/*   Updated: 2022/12/13 14:31:08 by anollero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node_aux;
	t_list	*lst_aux;
	t_list	*node;

	if (lst == NULL)
		return (NULL);
	node_aux = ft_lstnew(f(lst -> content));
	if (node_aux == NULL)
		return (NULL);
	lst_aux = lst -> next;
	while (lst_aux != NULL)
	{
		node = ft_lstnew(f(lst_aux -> content));
		if (node == NULL)
		{
			ft_lstclear(&node_aux, del);
			return (NULL);
		}
		ft_lstadd_back(&node_aux, node);
		lst_aux = lst_aux -> next;
	}
	return (node_aux);
}
