/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anollero <anollero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:53:55 by anollero          #+#    #+#             */
/*   Updated: 2022/11/22 16:51:38 by anollero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*lstaux;

	lstaux = lst;
	if (lst == NULL)
		return (lst);
	while (lstaux != NULL && lstaux -> next != NULL)
		lstaux = lstaux -> next;
	return (lstaux);
}
