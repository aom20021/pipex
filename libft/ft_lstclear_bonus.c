/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anollero <anollero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:05:34 by anollero          #+#    #+#             */
/*   Updated: 2022/12/28 13:45:29 by anollero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;
	t_list	*next;

	if (!del || !lst || !(*lst))
		return ;
	node = *lst;
	next = *lst;
	while (node != NULL)
	{
		del(node -> content);
		next = node -> next;
		free(node);
		node = next;
	}
	*(lst) = NULL;
}
