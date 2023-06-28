/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anollero <anollero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:04:07 by anollero          #+#    #+#             */
/*   Updated: 2023/05/04 14:01:37 by anollero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*join;

	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	join = (char *)malloc(len);
	if (join == 0)
		return (0);
	ft_bzero(join, len);
	ft_strlcpy(join, s1, len);
	ft_strlcpy((join + ft_strlen(s1)), s2, len);
	return (join);
}
