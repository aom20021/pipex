/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anollero <anollero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 11:12:39 by anollero          #+#    #+#             */
/*   Updated: 2022/10/09 15:11:57 by anollero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_compare(const char *big, const char *little, size_t count, size_t len)
{
	int	l_count;
	int	res;

	res = 1;
	l_count = 0;
	while (big[count] == little[l_count] && little[l_count] != '\0')
	{
		l_count++;
		count++;
		if (big[count] != little[l_count] && little[l_count] != '\0')
			res = 0;
	}
	if (len < count)
		return (0);
	return (res);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	count;
	char	*res;

	count = 0;
	res = 0;
	if (len < 0)
		return (0);
	if (little[0] == '\0' || (little[0] == '\0' && big[0] == '\0'))
		return ((char *)big);
	while (count != len && big[count] != '\0' && res == 0)
	{
		if (big[count] == little[0])
		{
			if (ft_compare(big, little, count, len))
				res = (char *)&big[count];
		}
		if (big[count] != '\0')
			count++;
	}
	return (res);
}
