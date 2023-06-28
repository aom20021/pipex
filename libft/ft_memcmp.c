/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anollero <anollero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 19:25:41 by anollero          #+#    #+#             */
/*   Updated: 2022/10/02 15:44:35 by anollero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t	count;
	int		ret_value;

	ret_value = 0;
	count = 0;
	while ((ret_value == 0) && count < n)
	{
		if (((unsigned char *)str1)[count] != ((unsigned char *)str2)[count])
		{
			ret_value = (unsigned char)((char *)str1)[count]
				- (unsigned char)((char *)str2)[count];
		}
		count++;
	}
	if (ret_value == 0 && count < n)
	{
		ret_value = (unsigned char)((char *)str1)[count]
			- (unsigned char)((char *)str2)[count];
	}
	return (ret_value);
}
