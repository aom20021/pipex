/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anollero <anollero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 16:49:17 by anollero          #+#    #+#             */
/*   Updated: 2022/09/21 19:09:46 by anollero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memset(void *str, int c, size_t n)
{
	size_t	pointer;

	pointer = 0;
	while (pointer != n)
	{
		*((char *)str + pointer) = c;
		pointer++;
	}
	return (str);
}
