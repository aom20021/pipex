/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anollero <anollero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 17:40:25 by anollero          #+#    #+#             */
/*   Updated: 2022/09/21 17:44:25 by anollero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	pointer;

	pointer = 0;
	while (pointer != n && (dest != NULL || src != NULL))
	{
		*((unsigned char *)dest + pointer) = *((unsigned char *)src + pointer);
		pointer++;
	}
	return (dest);
}
