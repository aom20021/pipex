/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anollero <anollero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 17:37:31 by anollero          #+#    #+#             */
/*   Updated: 2022/09/16 13:47:05 by anollero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_bzero(void *s, size_t n)
{
	size_t	pointer;

	pointer = 0;
	while (pointer != n)
	{
		*((unsigned char *)s + pointer) = '\0';
		pointer++;
	}
}
