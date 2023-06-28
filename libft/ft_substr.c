/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anollero <anollero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:27:10 by anollero          #+#    #+#             */
/*   Updated: 2022/12/09 13:42:23 by anollero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	count;
	char	*substr;

	if (!s)
		return (0);
	if (start > ft_strlen(s))
	{
		substr = (char *)ft_calloc(1, 1);
		return (substr);
	}
	if (ft_strlen(&s[start]) < len)
	{
		substr = (char *)ft_calloc(ft_strlen(&s[start]) + 1, 1);
		count = ft_strlen(&s[start]) + 1;
	}
	else
	{	
		substr = (char *)ft_calloc(len + 1, 1);
		count = len + 1;
	}
	if (substr == 0)
		return (0);
	ft_strlcpy(substr, &s[start], count);
	return (substr);
}
