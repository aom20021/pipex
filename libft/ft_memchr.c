/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anollero <anollero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 15:45:21 by anollero          #+#    #+#             */
/*   Updated: 2022/10/04 16:32:16 by anollero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	pointer;
	char	c2;

	c2 = c;
	pointer = 0;
	while (pointer < n && ((char *)s)[pointer] != c2)
	{
		pointer++;
	}
	if (pointer == n)
		return (0);
	return ((void *)(s + pointer));
}
