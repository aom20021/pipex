/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anollero <anollero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 17:50:43 by anollero          #+#    #+#             */
/*   Updated: 2022/10/02 15:44:58 by anollero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	unsigned char	*dest;
	unsigned char	*src;
	size_t			count;

	count = 0;
	if (n <= 0 || (str1 == NULL && str2 == NULL))
		return (str1);
	dest = (unsigned char *)str1;
	src = (unsigned char *)str2;
	if (src >= dest)
		ft_memcpy(dest, src, n);
	else
	{
		count = n - 1;
		while (count != 0)
		{
			dest[count] = src[count];
			count--;
		}
		dest[count] = src[count];
	}
	return (str1);
}
