/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anollero <anollero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:10:57 by anollero          #+#    #+#             */
/*   Updated: 2022/10/08 14:49:11 by anollero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_in_set(char c1, char const *set)
{
	int	count;

	count = 0;
	while (set[count] != c1 && set[count] != '\0')
	{
		count++;
	}
	if (c1 == '\0')
		return (1);
	if (set[count] == '\0')
		return (0);
	else
		return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	counts;
	int	countf;

	if (!s1 || !set)
		return (0);
	counts = 0;
	while (ft_is_in_set(s1[counts], set) && s1[counts] != '\0')
		counts++;
	countf = ft_strlen(s1);
	while (ft_is_in_set(s1[countf], set) && countf != 0)
		countf--;
	return (ft_substr(s1, counts, countf - counts + 1));
}
