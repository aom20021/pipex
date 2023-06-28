/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anollero <anollero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:17:50 by anollero          #+#    #+#             */
/*   Updated: 2022/10/08 15:55:25 by anollero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*res;
	size_t	count;

	if (nitems > 0 && (size > (SIZE_MAX / nitems)))
		return (0);
	count = 0;
	res = malloc(nitems * size);
	if (res == 0)
		return (0);
	while (count < nitems * size)
	{
		((unsigned char *)res)[count] = 0;
		count++;
	}
	return (res);
}
